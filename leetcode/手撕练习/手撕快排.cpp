#include<iostream>
#include<vector>

/*
用时20分钟
严重错误：没有递归条件
牢记 内外层循环条件是l < r ，和nums[l] <= xxx;
*/

using namespace std;




void quicSort(vector<int>&nums, int left, int right){
    if (left >= right) return;
    

    int l = left, r = right;
    int key = nums[l];
    while (l < r)
    {
        while (l < r && nums[r] >= key) r--;
        nums[l] = nums[r];
        while(l < r && nums[l] <= key) l++;
        nums[r] = nums[l];
    }
    nums[l] = key;
    quicSort(nums, left, l-1);
    quicSort(nums, l + 1, right);

}



int main(){


    vector<int>nums{1,8,54,3,6,4,6,4};
    quicSort(nums, 0, 7);
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    

    return 0;
}