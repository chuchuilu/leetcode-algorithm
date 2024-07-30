#include <iostream>
#include <string>
using namespace std;

// 函数：将数字转换为指定进制，并返回其中 '1' 的个数
int countOnesInBase(int number, int base) {
    int count = 0;
    while (number > 0) {
        if (number % base == 1) {
            count++;
        }
        number /= base;
    }
    return count;
}

int main() {
    int n;
    cin >> n; // 读取输入的十进制数

    int maxOnes = 0;
    for (int base = 2; base <= 36; ++base) {
        int onesCount = countOnesInBase(n, base);
        if (onesCount > maxOnes) {
            maxOnes = onesCount;
        }
    }

    cout << maxOnes << endl;
    return 0;
}
