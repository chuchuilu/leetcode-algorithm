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

/*
`std::unique_lock` 和 `std::lock_guard` 都是 C++ 标准库中用于管理互斥锁的 RAII（Resource Acquisition Is Initialization）类，但它们在灵活性和功能上有所不同。以下是它们的详细区别：

### `std::lock_guard`

`std::lock_guard` 是一个简单的、轻量级的锁管理类，用于在作用域内自动管理互斥锁的锁定和解锁。它在构造时锁定互斥锁，在析构时自动解锁。

#### 特点

1. **简单性**：`std::lock_guard` 非常简单，没有额外的功能。
2. **效率高**：由于功能简单，`std::lock_guard` 的开销很低。
3. **不可变**：一旦创建，就无法手动解锁或重新锁定，锁定状态在整个生命周期内保持不变。

#### 用法

```cpp
std::mutex mtx;

void some_function() {
    std::lock_guard<std::mutex> lock(mtx);  // 锁定互斥锁
    // 互斥锁在整个作用域内保持锁定
    // 作用域结束时自动解锁
}
```

### `std::unique_lock`

`std::unique_lock` 是一个更灵活的锁管理类，提供了许多高级功能。它也在构造时锁定互斥锁，在析构时自动解锁，但还允许手动控制锁的状态。

#### 特点

1. **灵活性**：可以手动锁定和解锁，可以延迟锁定，还可以尝试锁定（尝试获取锁而不阻塞）。
2. **条件变量兼容**：`std::unique_lock` 可以与条件变量一起使用，因为它允许在等待时释放锁并在唤醒时重新锁定。
3. **开销略高**：由于其灵活性，`std::unique_lock` 的开销比 `std::lock_guard` 稍高。

#### 用法

```cpp
std::mutex mtx;

void some_function() {
    std::unique_lock<std::mutex> lock(mtx);  // 锁定互斥锁
    // 互斥锁在整个作用域内保持锁定
    // 作用域结束时自动解锁

    lock.unlock();  // 手动解锁

    // 可以在之后的代码中重新锁定
    lock.lock();
}

void condition_variable_example() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock);  // 等待条件变量，并在等待时自动解锁，在唤醒时重新锁定
}
```

### 主要区别总结

1. **锁定管理**：
   - `std::lock_guard`：在创建时自动锁定，在销毁时自动解锁。锁定状态在整个生命周期内保持不变。
   - `std::unique_lock`：提供更灵活的锁管理，可以手动锁定、解锁和尝试锁定。

2. **条件变量支持**：
   - `std::lock_guard`：不能与条件变量一起使用，因为它不允许在等待时解锁。
   - `std::unique_lock`：可以与条件变量一起使用，因为它支持在等待时自动解锁并在唤醒时重新锁定。

3. **开销和性能**：
   - `std::lock_guard`：功能简单，开销低。
   - `std::unique_lock`：功能丰富，开销稍高。

### 选择指南

- 如果需要简单的锁定和解锁，并且不需要条件变量，可以选择 `std::lock_guard`。
- 如果需要更灵活的锁管理，或者需要与条件变量一起使用，应选择 `std::unique_lock`。


*/