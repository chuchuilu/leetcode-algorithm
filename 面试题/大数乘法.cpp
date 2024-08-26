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
std::string divide(std::string num1, std::string num2) {
    if (num2 == "0") return "error"; // 除数不能为0
    if (num1 == "0") return "0"; // 被除数为0，结果为0

    int n1 = num1.size();
    int n2 = num2.size();
    
    if (n1 < n2 || (n1 == n2 && num1 < num2)) return "0"; // 被除数小于除数，商为0

    std::string quotient;
    std::string remainder;

    // 从高位到低位遍历被除数
    for (int i = 0; i < n1; ++i) {
        remainder.push_back(num1[i]);
        
        // 移除余数的前导零
        while (remainder.size() > 1 && remainder[0] == '0') {
            remainder.erase(0, 1);
        }

        // 计算当前位的商
        int count = 0;
        while (remainder.size() > n2 || (remainder.size() == n2 && remainder >= num2)) {
            int len = num2.size();
            std::string temp = remainder.substr(0, len);
            if (temp < num2) {
                len++;
                temp = remainder.substr(0, len);
            }
            
            // 模拟大数减法
            int carry = 0;
            for (int j = len - 1, k = num2.size() - 1; k >= 0; --j, --k) {
                int sub = (remainder[j] - '0') - (num2[k] - '0') - carry;
                if (sub < 0) {
                    sub += 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                remainder[j] = sub + '0';
            }
            // 清除前导零
            while (remainder.size() > 1 && remainder[0] == '0') {
                remainder.erase(0, 1);
            }

            count++;
        }
        quotient.push_back(count + '0');
    }

    // 移除商的前导零
    while (quotient.size() > 1 && quotient[0] == '0') {
        quotient.erase(0, 1);
    }

    return quotient;
}




int main(){
    string num1 = "123";
    string num2 = "456";
    cout << multiply(num1, num2) << endl;
    std::string numd1 = "123456789";
    std::string numd2 = "123";
    std::cout << divide(numd1, numd2) << std::endl; // 输出: 1003713


    return 0;
}