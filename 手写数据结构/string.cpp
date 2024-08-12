#include <iostream>
#include <stdexcept>
#include <cstring>

class String {
private:
    char* data;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity) {
        char* new_data = new char[new_capacity];
        std::memcpy(new_data, data, size);
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    String(): data(nullptr), size(0), capacity(0) {}

    String(const char* str): size(std::strlen(str)), capacity(size) {
        data = new char[capacity + 1];
        std::memcpy(data, str, size);
        data[size] = '\0';
    }

    String(const String& other): size(other.size), capacity(other.capacity) {
        data = new char[capacity + 1];
        std::memcpy(data, other.data, size);
        data[size] = '\0';
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new char[capacity + 1];
            std::memcpy(data, other.data, size);
            data[size] = '\0';
        }
        return *this;
    }

    ~String() {
        delete[] data;
    }

    void push_back(char ch) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = ch;
        data[size] = '\0';
    }

    char& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const char& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

    const char* c_str() const {
        return data;
    }

    // 迭代器支持
    char* begin() {
        return data;
    }

    char* end() {
        return data + size;
    }

    const char* begin() const {
        return data;
    }

    const char* end() const {
        return data + size;
    }

    // 拼接字符串
    String& operator+=(const String& other) {
        for (size_t i = 0; i < other.size; i++) {
            push_back(other.data[i]);
        }
        return *this;
    }
};

int main() {
    String str("Hello");
    str.push_back(' ');
    str += String("World!");

    for (char ch : str) {
        std::cout << ch;
    }
    std::cout << std::endl;

    std::cout << "Size: " << str.get_size() << std::endl;
    std::cout << "Capacity: " << str.get_capacity() << std::endl;

    return 0;
}
