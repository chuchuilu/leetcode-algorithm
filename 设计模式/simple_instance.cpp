#include <iostream>
#include <algorithm>

class SingleInstance{
public:
    static SingleInstance* GetInstance(){
        static SingleInstance ins;
        return &ins;
    }
    ~SingleInstance(){};

    int a;
private:
    SingleInstance(){ 
        a = a + 1;
        std::cout << "a = " << a << std::endl;
        std::cout << "单例模式create" << std::endl;}
    SingleInstance(const SingleInstance &other) = delete;
    SingleInstance& operator= (const SingleInstance&other) = delete;

};


int main(){
    SingleInstance* simle_instance = SingleInstance::GetInstance();

    SingleInstance* simple_instance = SingleInstance::GetInstance();


    return 0;
}