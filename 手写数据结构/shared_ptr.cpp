#include <iostream>
#include <memory>

template<typename T>
class shared_ptr {
public:
    shared_ptr(T* ptr = nullptr): _ptr(ptr), _pcount(new int(1)) {}

    shared_ptr(const shared_ptr& sp): _ptr(sp._ptr), _pcount(sp._pcount) {
        ++(*_pcount);
    }

    shared_ptr& operator=(const shared_ptr& sp){
        if (this != &sp)
        {
            if (_pcount&&--(*_pcount) == 0)
            {
                delete _ptr;
                delete _pcount;
            }
            _ptr = sp._ptr;
            _pcount = sp._pcount;
            ++(*_pcount);
            
        }
        return *this;
    }

    T& operator*(){
        return *_ptr;
    }

    T* operator->(){
        return this -> _ptr;
    }


    ~shared_ptr(){
        if (--(*_pcount) == 0)
        {
            delete _ptr;
            delete _pcount;
        }
    }

    int use_cout() const {
        return *_pcount;
    }



private:
    T* _ptr;
    int* _pcount;
    
};


int main(){
    shared_ptr<int> sp(new int(10));
    shared_ptr<int> sp2(sp);
    std::cout << *sp << std::endl;
    std::cout << *sp2 << std::endl;
    std::cout << sp.use_cout() << std::endl;

    return 0;
}