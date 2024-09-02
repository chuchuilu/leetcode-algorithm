/*
基数排序（Radix Sort）是一种非比较排序算法，特别适用于按位数进行排序的整数或字符串。基数排序通过将元素按位分配到桶中，逐位处理，最终得到有序序列。它通常用于排序非负整数，但也可以通过一些修改处理其他数据类型。

基数排序的工作原理
基数排序的基本思想是：按照从最低有效位（LSD）到最高有效位（MSD）的顺序，依次对每一位进行排序。每一位的排序可以使用稳定的排序算法（如计数排序或桶排序）来确保排序过程的正确性。

基本步骤如下：

确定最大位数：找到待排序数组中最大元素的位数，决定排序过程需要多少轮。

逐位排序：从最低有效位开始（例如个位数），对所有元素进行一次稳定排序。然后对下一位（十位数）进行排序，依此类推，直到最高有效位。

合并结果：经过所有位数的排序后，数组即为有序。


*/
#include <iostream>
#include <vector>
#include <algorithm>

// 获取数组中的最大值
int getMax(const std::vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// 使用计数排序对数组的指定位进行排序
void countingSortForRadix(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n); // 输出数组
    int count[10] = {0}; // 计数数组，初始化为0

    // 计算每个数字出现的次数
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // 计算累积计数
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 从右到左将元素放入输出数组中，确保稳定性
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // 将输出数组复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 基数排序函数
void radixSort(std::vector<int>& arr) {
    int maxVal = getMax(arr); // 获取最大值

    // 对数组的每一位（个位、十位、百位等）进行计数排序
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}

// 主函数，测试基数排序
int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "排序前的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 调用基数排序函数
    radixSort(arr);

    std::cout << "排序后的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
