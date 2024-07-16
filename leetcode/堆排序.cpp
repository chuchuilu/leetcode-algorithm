#include <iostream>
#include <vector>

using namespace std;

// 用于维护堆的性质的函数
void heapify(vector<int>& nums, int n, int i) {
    int largest = i; // 初始化最大值为根节点
    int left = 2 * i + 1; // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点存在且大于根节点
    if (left < n && nums[left] > nums[largest])
        largest = left;

    // 如果右子节点存在且大于当前最大值
    if (right < n && nums[right] > nums[largest])
        largest = right;

    // 如果最大值不是根节点，则交换并继续堆化
    if (largest != i) {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

// 堆排序函数
void heapSort(vector<int>& nums) {
    int n = nums.size();

    // 建立最大堆，从最后一个非叶子节点开始
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);

    // 一个一个地从堆中取出元素，并调整堆
    for (int i = n - 1; i >= 0; i--) {
        // 将当前最大的元素（堆顶）放到数组末尾
        swap(nums[0], nums[i]);

        // 重新调整堆
        heapify(nums, i, 0);
    }
}

int main() {
    vector<int> nums{1, 56, 3, 6, 4, 8, 4};
    heapSort(nums);
    for (auto num : nums)
        cout << num << " ";
    return 0;
}
