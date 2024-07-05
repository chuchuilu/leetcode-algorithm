#include<iostream>


template<typename T>
class Shared_ptr{
public:
    Shared_ptr(T* sp = nullptr): _ptr(sp), _pcount(new int(sp ? 1: 0)){}
    Shared_ptr(const Shared_ptr& sp): _ptr(sp._ptr), _pcount(sp._pcount){
        if (_ptr)
        {
            ++(*_pcount);
        }
        
    }

    Shared_ptr& operator=(const Shared_ptr&sp){
        if (this != &sp)
        {
            if (_pcount&& --*(_pcount) == 0)
            {
                delete _ptr;
                delete _pcount;
            }
            _pcount = sp._pcount;
            _ptr = sp._ptr;
            if (_ptr)
            {
                ++(*_pcount);
            }
        }
        return *this;
    }

    
    T& operator*() const{
        return *_ptr;
    }

    T* operator->() const{
        return _ptr;
    }

    int use_count() const{
        return *_pcount;
    }


    ~Shared_ptr(){
        if (_pcount && --(*_pcount) == 0)
        {
            delete _ptr;
            delete _pcount;
        }
    }



private:
    T* _ptr;
    int* _pcount;

};


int main(){

    Shared_ptr<int>sp(new int(5));
    Shared_ptr<int>sp1(sp);
    Shared_ptr<int>sp3;
    sp3 = sp;
    std::cout << sp.use_count() << std::endl;
    std::cout << sp3.use_count() << std::endl;



    return 0;
}
