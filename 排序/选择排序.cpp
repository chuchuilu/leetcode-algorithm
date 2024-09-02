#include <iostream>

using namespace std;

void selectionSort(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n - 1; i++){
        int minidx = i;
        for(int j = i + 1; i < n; j++){
            if(nums[j] < nums[minidx])  minidx = j;
        }
        if(minidx != i) swap(nums[i], nums[minidx]);
    }
}