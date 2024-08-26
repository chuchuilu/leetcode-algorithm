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




int main(){
    string num1 = "123";
    string num2 = "456";
    cout << multiply(num1, num2) << endl;


    return 0;
}