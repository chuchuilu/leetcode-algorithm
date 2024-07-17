#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>

// 定义互斥锁
std::mutex mtx;

// 定义条件变量，做线程同步
std::condition_variable cv;

// 定义vector作为容器
std::vector<int> vec;

// 生产者线程函数
void producer()
{
    // 生产者每生产一个就通知消费者消费一个
    for(int i = 0; i < 10; i++)
    {
        // 获取mtx互斥资源
        std::unique_lock<std::mutex> lock(mtx);

        // 如果容器不为空，还有没消费，先不生产
        while(!vec.empty()){
            // 等待条件变量，释放锁，并阻塞
            cv.wait(lock);
        }
        // 容器为空，那就生产
        vec.push_back(i);
        std::cout << "producer 生产产品: " << i + 1 << std::endl;

        // ok,产品生产完了，通知等待条件变量上的各位消费
        cv.notify_all();

        // 生产一个产品，睡眠100ms
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


//消费者线程函数
void consumer(){
    for(int i = 0; i < 10; i++){
        // 消费者获取锁
        std::unique_lock<std::mutex> lock(mtx);

        // 判断容器是否为空 空 释放阻塞 || 不为空 则消费
        while(vec.empty()){
            cv.wait(lock);
        }

        // 不为空，则消费
        vec.pop_back();
        std::cout << "consumer 消费产品 " << i + 1 << std::endl;

        // 消费完了，notify一下生产者，别阻塞了，准备就绪
        cv.notify_all();



    }
}



int main(){

    std::cout << "准备开始生产消费: " << std::endl;

    std::thread producer_thread(producer);
    std::thread consumer_thraed(consumer);
    // producer_thread(producer);
    // consumer_thraed(consumer);

    producer_thread.join();
    consumer_thraed.join();

    std::cout << "消费完了，结束" << std::endl;



    return 0;
}