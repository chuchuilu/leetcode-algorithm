#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t size;
    size_t capacity;

    void allocate_capacity(size_t new_capacity) {
        if (new_capacity > capacity) {
            char* new_data = new char[new_capacity + 1];
            if (data) {
                std::memcpy(new_data, data, size);
                new_data[size] = '\0';
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }

public:
    // 默认构造函数
    String() : data(nullptr), size(0), capacity(0) {}

    // C字符串构造函数
    String(const char* str) {
        size = std::strlen(str);
        capacity = size;
        data = new char[capacity + 1];
        std::memcpy(data, str, size);
        data[size] = '\0';
    }

    // 拷贝构造函数
    String(const String& other) {
        size = other.size;
        capacity = other.capacity;
        data = new char[capacity + 1];
        std::memcpy(data, other.data, size);
        data[size] = '\0';
    }

    // 移动构造函数
    String(String&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // 拷贝赋值运算符
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

    // 移动赋值运算符
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            capacity = other.capacity;
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // 析构函数
    ~String() {
        delete[] data;
    }

    // 返回字符串大小
    size_t length() const {
        return size;
    }

    // 返回容量
    size_t get_capacity() const {
        return capacity;
    }

    // 预留空间
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity) {
            allocate_capacity(new_capacity);
        }
    }

    // 修改大小
    void resize(size_t new_size, char c = '\0') {
        if (new_size > size) {
            reserve(new_size);
            std::memset(data + size, c, new_size - size);
        }
        size = new_size;
        data[size] = '\0';
    }

    // 获取C字符串
    const char* c_str() const {
        return data;
    }

    // 访问字符
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

    // 字符串连接
    String& operator+=(const String& other) {
        size_t new_size = size + other.size;
        if (new_size > capacity) {
            reserve(new_size);
        }
        std::memcpy(data + size, other.data, other.size);
        size = new_size;
        data[size] = '\0';
        return *this;
    }

    // 输出运算符
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        if (str.data) {
            os << str.data;
        }
        return os;
    }
};

int main() {
    String str1 = "Hello";
    String str2 = " World!";
    String str3 = str1;
    str3 += str2;

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    std::cout << "Length of str3: " << str3.length() << std::endl;
    std::cout << "Capacity of str3: " << str3.get_capacity() << std::endl;

    return 0;
}
