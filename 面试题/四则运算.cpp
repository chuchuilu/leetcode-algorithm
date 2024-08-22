#include <iostream>
#include <string>
#include <stack>
#include <cctype>

int calculate(const std::string& s) {
    std::stack<int> nums; // 数字栈
    std::stack<char> ops; // 运算符栈
    int num = 0;
    char op = '+';
    for (size_t i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1) {
            if (op == '+' || op == '-') {
                nums.push(op == '+' ? num : -num);
            } else if (op == '*' || op == '/') {
                int top = nums.top();
                nums.pop();
                nums.push(op == '*' ? top * num : top / num);
            }
            op = s[i];
            num = 0;
        }
    }

    int result = 0;
    while (!nums.empty()) {
        result += nums.top();
        nums.pop();
    }

    return result;
}

int main() {
    std::string expression;
    std::cout << "输入一个字符串表达式: ";
    std::cin >> expression;
    // std::getline(std::cin, expression);
    
    int result = calculate(expression);
    std::cout << "结果: " << result << std::endl;

    return 0;
}
