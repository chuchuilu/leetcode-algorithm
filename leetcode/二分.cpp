#include<iostream>
#include<vector>

using namespace std;

bool binary_search(vector<int>&nums, int target){
    int left = 0, right = nums.size() - 1;
    
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else    return true;
        
    }
    return false;
    
    
}


int main(){
    vector<int>nums{1,2,5,6,8};
    cout << binary_search(nums, 7) << " ";



    return 0;
}