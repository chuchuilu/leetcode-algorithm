#include<iostream>
#include<memory>



template<typename T>
class shared_ptr{
public:
    shared_ptr(T* ptr = nullptr): _ptr(ptr), _pcount(new int(ptr? 1: 0)){}
    
    shared_ptr(const shared_ptr &sp): _ptr(sp._ptr), _pcount(sp._pcount){
        if(_ptr){
            (*_pcount) ++;
        }

    }

    shared_ptr& operator=(const shared_ptr &sp){
        if (this != &sp){
            if (_pcount&& --(*_pcount) == 0 )
            {
                delete _ptr;
                delete _pcount;
            }
            _ptr = sp._ptr;
            _pcount = sp._pcount;
            if (_ptr)
            {
                ++(*_pcount);
            }
            

        }
        return *this;
    }

    T& operator*(){
        return *_ptr;
    }

    T* operator->(){
        return this -> _ptr;
    }

    int usecount() const{
        return *_pcount;
    }

    ~shared_ptr(){
        if (_ptr && --(*_pcount) == 0)
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
    shared_ptr<int>sp(new int(100));
    shared_ptr<int>sp2(sp);
    shared_ptr<int>sp3;
    sp3 = sp;
    std::cout << sp.usecount() << std::endl;
    std::cout << sp3.usecount() << std::endl;


    return 0;
}