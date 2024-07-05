#include<iostream>

template<typename T>
class Unique_ptr{
public:
    // 构造函数
    explicit Unique_ptr(T* ptr = nullptr): _ptr(ptr){}

    // 禁用拷贝构造
    Unique_ptr(const Unique_ptr&) = delete;

    // 禁用拷贝赋值
    Unique_ptr& operator=(const Unique_ptr& up) = delete;

    // 移动构造函数
    Unique_ptr(Unique_ptr&& up) noexcept: _ptr(up._ptr){
        up._ptr = nullptr;
    }

    // 移动赋值
    Unique_ptr& operator=(Unique_ptr&& up) noexcept{
        if (this != &up)
        {
            delete _ptr;
            _ptr = up._ptr;
            up._ptr = nullptr;
        }
        return *this;
    }

    // 解引用
    T& operator*() const {
        return *_ptr;
    }

    // 成员操作
    T* operator->() const{
        return this -> _ptr;
    }

    // 返回托管对象
    T* get() const {
        return _ptr;
    }

    // 释放所有权
    T* release(){
        T* temp = _ptr;
        _ptr = nullptr;
        return temp;
    }

    //重置托管对象
    void reset (T* ptr = nullptr){
        delete _ptr;
        _ptr = ptr;
    }

    ~Unique_ptr(){
        delete _ptr;
    }
    

private:
    T* _ptr;
};

int main(){
    // 创建一个Unique_ptr
    Unique_ptr<int> up(new int(100));
    std::cout << *up << std::endl;

    // 转移所有权
    Unique_ptr<int> up2 = std::move(up);


    // reset
    up2.reset(new int(200));
    
    // release
    int *p = up2.release();
    
    delete p;


    return 0;
}