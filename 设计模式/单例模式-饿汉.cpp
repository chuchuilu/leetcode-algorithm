// 程序启动即创建 已经实例化 线程安全不用加锁
#include <iostream>
#include <algorithm>

using namespace std;

class SingleInsatance{
public:
    static SingleInsatance* GetInstance(){
        static SingleInsatance ins; // 静态局部变量
        return &ins;
    }

    ~SingleInsatance(){};

private:
    // 涉及创建对象的函数都设置为private
    SingleInsatance() { cout << "SingleInsatance( ) 饿汉" << endl;}
    SingleInsatance(const SingleInsatance &other) {} = delete;
    SingleInsatance& operator=(const SingleInsatance& other) = delete;


};

int main(){
    SingleInsatance* ins = SingleInsatance::GetInstance();
    SingleInsatance* ininsss = SingleInsatance::GetInstance();
    return 0;
}