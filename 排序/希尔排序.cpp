/*
希尔排序（Shell Sort）是一种基于插入排序的排序算法，它通过将数组分成多个子序列进行排序，逐步减少子序列间的间隔，最终达到整体有序。希尔排序的核心思想是通过“分组插入排序”来减少元素移动的距离，提高排序效率。

希尔排序的工作原理
希尔排序的基本步骤如下：

选择一个增量序列: 增量序列决定了数组被分成的子序列。最初的增量（gap）较大，随后逐步减少，最后一个增量为1。
分组排序: 对于每一个增量，按该增量将数组分组，对每个分组使用插入排序。
缩小增量: 将增量逐步缩小，重复步骤2，直到增量为1。
最终排序: 当增量为1时，整个数组进行一次标准插入排序，最终数组完全有序。

*/

#include <iostream>
#include <vector>

// 希尔排序函数
void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // 初始间隔设置为数组长度的一半，逐渐缩小间隔
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个间隔大小为gap的子序列进行插入排序
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            // 在子序列内进行插入排序
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // 放置临时存储的值到合适的位置
            arr[j] = temp;
        }
    }
}

// 主函数，测试希尔排序
int main() {
    std::vector<int> arr = {12, 34, 54, 2, 3};
    
    std::cout << "排序前的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // 调用希尔排序函数
    shellSort(arr);
    
    std::cout << "排序后的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
