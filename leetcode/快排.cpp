#include<iostream>
#include<vector>
using namespace std;

void quic_sort(vector<int> &nums, int l, int r){
    if(l > r) return;
    int left = l,right = r;
    int key = nums[left];
    while (left < right)
    {
        while (left < right && nums[right] >= key) right--;
        nums[left] = nums[right];
        while (left < right && nums[left] <= key) left++;
        nums[right] = nums[left];
    }

    nums[right] = key;
    quic_sort(nums, l, right - 1);
    quic_sort(nums, right + 1, r);
}


int main(){
    vector<int> nums{1,3,4,6,3,5,9,6,9,84,100000000};

    quic_sort(nums, 0, nums.size() - 1);
    for(auto const &num: nums){
        cout << num << " ";
    }

    return 0;
}