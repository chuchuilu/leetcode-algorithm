class Solution {
public:
    void quick_sort(vector<int>& nums, int left, int right, int k){
        if(left >= right)   return;
        int l = left, r = right;
        int pvot = nums[l];
        while(l < r){
            while(l < r&& nums[r] <= pvot)  r--;
            nums[l] = nums[r];
            while(l < r && nums[l] >= pvot) l++;
            nums[r] = nums[l];
        }
        nums[l] = pvot;

        if(l == k - 1)  return;
        quick_sort(nums,left, l - 1 , k);
        quick_sort(nums,l + 1, right, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        // 第k个最大 倒数第 n - k + 1个
        quick_sort(nums, 0, nums.size() - 1, k);
        return nums[k - 1];
    }
};