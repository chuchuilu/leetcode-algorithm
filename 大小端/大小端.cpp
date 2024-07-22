#include<iostream>

using namespace std;

int main(){
    int a = 0x1234;
    char c = (char)a;
    // 强制转换只会留下最低位
    if(c == 0x12){
        cout << "大端" << endl;
    }else{
        cout << "小端" << endl;
    }
}