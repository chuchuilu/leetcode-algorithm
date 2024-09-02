/*
计数排序（Counting Sort）是一种非比较排序算法，特别适用于排序整数范围已知且较小的数据集。它通过统计每个元素出现的次数，然后按照元素大小顺序排列输出，实现线性时间复杂度的排序。

计数排序的工作原理
计数排序的基本步骤如下：

找出数组中的最大值和最小值：

确定数据的范围，以便分配计数数组的大小。
创建计数数组：

创建一个计数数组 count，其大小为最大值与最小值的差加1，用于统计每个元素出现的次数。
填充计数数组：

遍历待排序数组 arr，对于每个元素 arr[i]，增加对应计数数组 count[arr[i] - min] 的计数。
累加计数数组（可选步骤，如果需要输出稳定的排序）：

累加计数数组，count[i] 存储的是数组中小于等于 i + min 的元素数量。
构建输出数组：

从右向左遍历输入数组 arr，根据计数数组的值将元素放入输出数组 output 的正确位置，并更新计数数组以反映已经放置的元素。
将排序后的数据拷贝回原数组（或直接返回输出数组）：

将排序后的结果写回到原数组 arr 或返回输出数组 output。

使用场景：
计数排序适用于：

    整数排序且范围已知的场景。
    数据范围不大、值域较小的情况，例如排序成绩、年龄等。
    需要线性时间复杂度的排序任务。
    计数排序不适用于：

    数据范围非常大时，因为计数数组需要大量的空间，导致空间复杂度过高。

*/

#include <iostream>
#include <vector>

// 计数排序函数
void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    // 找到数组中的最大值和最小值
    int min = *min_element(arr.begin(), arr.end());
    int max = *max_element(arr.begin(), arr.end());

    // 创建计数数组，范围为从min到max
    std::vector<int> count(max - min + 1, 0);

    // 填充计数数组
    for (int num : arr) {
        count[num - min]++;
    }

    // 将计数数组转换为排序后的数组
    int index = 0;
    for (int i = 0; i < count.size(); ++i) {
        while (count[i]-- > 0) {
            arr[index++] = i + min;
        }
    }
}

// 主函数，测试计数排序
int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    std::cout << "排序前的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 调用计数排序函数
    countingSort(arr);

    std::cout << "排序后的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
