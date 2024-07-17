#include<iostream>
#include<vector>

using namespace std;

void quick_sort(vector<int>& nums, int l, int r){
    if (l >= r) return;
    int left = l, right = r;
    int pvot = nums[left];
    while (left < right)
    {
        while(left < right && nums[right] >= pvot)  right--;
        nums[left] = nums[right];
        while(left < right && nums[left] <= pvot)   left++;
        nums[right] = nums[left];
    }
    nums[left] = pvot;
    quick_sort(nums, l, right - 1);
    quick_sort(nums, right + 1, r);
    
    
}


int main(){
    vector<int>nums{2,4,7,4,3,5,7,9};
    quick_sort(nums, 0, nums.size() - 1);
    for(int num: nums)  cout << num << " ";



    return 0;
}