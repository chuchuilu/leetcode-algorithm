#include <iostream>
#include <cmath>
#include <iomanip>

double sqrtBinarySearch(double x, double precision = 1e-6) {
    if (x < 0) return -1; // 如果x是负数，返回-1表示错误
    if (x == 0 || x == 1) return x;

    double low = 0, high = x, mid;
    while (high - low > precision) {
        mid = (low + high) / 2;
        if (mid * mid > x) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return (low + high) / 2;
}

/*
    牛顿法
*/
class Solution {
public:
    int mySqrt(int n) {
        double E = 1e-5;
        double x = 1.0;
        while(true){
            double next_x = (x + n / x) / 2;
            if(abs(x - next_x) < E) break;
            x = next_x;
        }
        return static_cast<int>(x);
    }
};

int main() {
    double number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    double result = sqrtBinarySearch(number);
    if (result == -1) {
        std::cout << "Square root of negative number is not defined." << std::endl;
    } else {
        std::cout << "Square root of " << number << " is approximately " 
                  << std::setprecision(10) << result << std::endl;
    }

    return 0;
}
