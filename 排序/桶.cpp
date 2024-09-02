#include <iostream>
#include <vector>
#include <algorithm>

/*
桶排序的工作原理
桶排序的基本步骤如下：

确定桶的数量和范围:

根据待排序数据的范围和数量，确定需要多少个桶以及每个桶的范围（区间）。
分配元素到桶:

将每个元素根据其值映射到相应的桶中（通常是根据元素的大小关系）。
对每个桶内进行排序:

对每个非空的桶内的元素进行排序。可以使用其他排序算法，比如插入排序、快速排序等，因为桶内的数据量通常较少。
合并所有桶:

将所有桶内的元素按顺序合并，得到最终的有序数组。

桶排序特别适用于数据分布均匀且已知范围的数据排序，如：

浮点数排序（假设数据在0到1之间均匀分布）。
应用于需要按范围划分数据的场景，比如成绩排序、分数统计等。


*/

// 桶排序函数
void bucketSort(std::vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // 创建 n 个桶，使用 vector 作为桶的容器
    std::vector<std::vector<float>> buckets(n);

    // 将每个元素放入对应的桶中
    for (int i = 0; i < n; ++i) {
        int bucketIndex = n * arr[i];  // 假设 arr[i] 的范围在 [0, 1)
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 对每个桶内的元素进行排序
    for (int i = 0; i < n; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // 将所有桶中的元素合并到 arr 中
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

// 主函数，测试桶排序
int main() {
    std::vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    
    std::cout << "排序前的数组: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 调用桶排序函数
    bucketSort(arr);

    std::cout << "排序后的数组: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
