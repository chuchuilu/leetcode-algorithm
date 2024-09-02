#include <iostream>

template<typename T>
class Queue{
public:
    Queue(int capacity = 0) :capacity(capacity), size(0), capacity(0),head(0),tail(0){
        data = new T[capacity];
    }

    int Size(){
        return size;
    }

    int Capcacity(){
        return capacity;
    }

    bool Empty(){
        return size == 0;
    }

    bool Push(const t& value){
        if(size == capacity)    return false;
        data[tail] = value;
        tail = (tail + 1) % capacity;
        size++;
    }

    bool Pop(){
        if(size == 0)   return false;
        head = (head + 1) % capacity;
        size--;
    }


private:
    T* data;
    int size;
    int capacity;
    int head;
    int tail;

}


int main(){



    return 0;
}