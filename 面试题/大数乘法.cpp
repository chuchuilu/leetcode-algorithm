#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

string multiply(string num1, string num2){
    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> res(n1 + n2, 0);

    for(int i = n1 - 1; i >= 0; i--){
        for(int j = n2 - 1; j >=0; j--){
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1];

            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    string product;
    for(int num: res){
        if(!(product.empty() && num == 0)){
            product.push_back(num + '0');
        }
    }
    return product.empty() ? "0" : product;
}

// 大数除法
string divide(string num1, string num2){
    if(num1 == "0") return "0";
    if(num2 == "0") return "error";

    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> res(n1, 0);

    for(int i = 0; i < n1; i++){
        int j = 0;
        while(j < n2){
            if(num1[i] == num2[j]){
                res[i] = 1;
                break;
            }
            j++;
        }
    }

    string product;
    for(int num: res){
        if(!(product.empty() && num == 0)){
            product.push_back(num + '0');
        }
    }
    return product.empty() ? "0" : product;
}




int main(){
    string num1 = "123";
    string num2 = "456";
    cout << multiply(num1, num2) << endl;


    return 0;
}