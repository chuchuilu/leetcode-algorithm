#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int maxAccumulate(vector<int>&nums){
    int n = nums.size();
    vector<int>dp_min(n);
    vector<int>dp_max(n);
    int ans = nums[0];
    dp_max[0] = nums[0];
    dp_min[0] = nums[0];
    for(int i = 1; i < n ;i++){
        dp_max[i] = max(max(nums[i], nums[i] * dp_max[i - 1]), nums[i] * dp_min[i - 1]);
        dp_min[i] = min(min(nums[i], nums[i] * dp_max[i - 1]), nums[i] * dp_min[i - 1]);
        ans = max(ans, dp_max[i]);
    }
    return ans;
}

int main(){
    vector<int> nums = {2, 3, -2, 4}; // 示例输入
    cout << "Maximum Product Subarray: " << maxAccumulate(nums) << endl;

    return 0;

}