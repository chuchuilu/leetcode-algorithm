#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>&nums, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(nums.begin() + left, nums.begin() + mid + 1);
    vector<int> R(nums.begin() + mid + 1, nums.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if (L[i] >= R[j])
        {
            nums[k] = R[j];
            j++;
        }
        else{
            nums[k] = L[i];
            i++;
        }
        k++;
    }
    while (n1 > i)  nums[k++] = L[i++];
    while (n2 > j)  nums[k++] = R[j++];
}

void merge_sort(vector<int>&nums, int left, int right){
    if (left >= right)  return;
    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
    
}

int main(){

    vector<int>nums{1,56,3,6,4,8,4};
    merge_sort(nums, 0, nums.size() - 1);
    for(auto num: nums) cout << num <<" ";
    return 0;
}