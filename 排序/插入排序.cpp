#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i - 1;
        // 将 nums[i] 插入到已排序部分
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

int main() {
    vector<int> nums = {3, 2, 1, 4, 1, 5};
    insertion_sort(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    return 0;
}