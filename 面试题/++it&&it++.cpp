class It{
    It(){};
    ~It(){};

    int& operator++(){
        // 不产生临时对象
        *this += 1;
        return *this;
    }

    int operator++(int){
        // 产生临时对象
        int temp = *this;
        *this += 1;
        return temp;
    }


};