#include <iostream>
#include <vector>


using namespace std;

void bubble_sort(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j < n - i; j++){
            if(nums[j] < nums[j - 1]){
                swap(nums[j], nums[j - 1]);                
            }
        }
    }
}


int main(){
    vector<int> nums = {3, 2, 1, 4,1, 5};
    bubble_sort(nums);
    for(auto num : nums){
        cout << num << " ";
    }
    return 0;
}