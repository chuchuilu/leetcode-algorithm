#include<iostream>
#include<initializer_list>



template<typename T>
class Vector{
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity){
        T* new_data = new T[new_capacity];
        for(size_t i = 0; i < size; i++){
            new_data[i] = data[i];
        }
        delete []data;
        data = new_data;
        capacity = new_capacity;
    }
public:
    Vector(): data(nullptr), capacity(0), size(0){}

    Vector(std::initializer_list<T> init_list): data(nullptr), capacity(0), size(0){
        for(const T& item : init_list){
            push_back(item);
        }
    }

    ~Vector(){
        delete[] data;
    }

    void push_back(const T& value){
        if(size == capacity){
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }

    T& operator[](size_t index){
        if(index >= size){
            throw std::out_of_range("out of range");
        }
        return data[index];
    }

    size_t get_size() const{
        return size;
    }

    size_t get_capacity() const{
        return capacity;
    };

        // 迭代器支持
    T* begin() {
        return data;
    }

    T* end() {
        return data + size;
    }
};



int main(){
    Vector<int>vec{1,4,5,6,7};
    for(int item: vec)  std::cout <<  item << " ";
    std::cout << std::endl;
    std::cout << vec.get_size() << std::endl;
    std::cout << vec.get_capacity() << std::endl;




    return 0;
}