#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <unordered_map>

// Helper function to perform arithmetic operations
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Function to calculate the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to evaluate the expression
int calculate(const std::string& s) {
    std::stack<int> nums;  // Stack to store integers
    std::stack<char> ops;  // Stack to store operators
    int num = 0;
    bool numInProgress = false;

    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the character is a digit, accumulate it into num
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
            numInProgress = true;
        } 

        // If the character is an operator or end of the string, process it
        if (!isdigit(c) && !isspace(c) || i == s.length() - 1) {
            if (numInProgress) {
                nums.push(num);
                num = 0;
                numInProgress = false;
            }

            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();
                nums.push(applyOp(a, b, op));
            }

            if (c != '\0') {
                ops.push(c);
            }
        }
    }

    // Final computation for the remaining operators in the stack
    while (!ops.empty()) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        nums.push(applyOp(a, b, op));
    }

    return nums.top();
}

int main() {
    std::string expression;
    std::cout << "输入一个字符串表达式: ";
    std::getline(std::cin, expression);

    int result = calculate(expression);
    std::cout << "结果: " << result << std::endl;

    return 0;
}
