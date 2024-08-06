#include<vector>
#include<climits>
#include<iostream>

using namespace std;

int climb(vector<int>nums, int k){
    int n = nums.size();
    vector<int>dp(n, INT_MIN);
    dp[0] = nums[0];
    for(int i = 1; i < n; i++){
        for(int j = 1 ; j <=k && (i - j) >= 0 ; j++){
            dp[i] = max(dp[i], dp[i-j] + nums[i]);
        }
    }
    return dp[n-1];
}

int main(){
    vector<int>nums{10, 20, 15, 25, 10, 15};
    int k = 3;
    cout << climb(nums, k) << endl;

    return 0;

}