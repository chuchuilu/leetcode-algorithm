#include<vector>
#include<climits>
#include<iostream>
#include<deque>

using namespace std;

// 单调队列 + 动态规划
// 时间复杂度O(n)
// 空间复杂度O(n)

int climb(vector<int>nums, int k){
    int n = nums.size();
    if(n == 1)  return nums[0];
    vector<int>dp(n, INT_MIN); // 爬到第i个 所获取的最大价值
    dp[0] = nums[0];
    deque<int>q;
    q.push_back(0);
    for(int i = 1; i < n; i++){
        dp[i] = dp[q.front()] + nums[i];
        while(!q.empty() && dp[i] > dp[q.back()]){
            q.pop_back();
        }
        if(i - q.front() >= k)  q.pop_front();
        q.push_back(i);
        // for(int j = 1 ; j <= k && (i - j) >= 0 ; j++){
        //     dp[i] = max(dp[i], dp[i-j] + nums[i]);
        // }

    }
    return dp[n-1];
}

int main(){
    vector<int>nums{10, 20, 15, 25, 10, 15};
    int k = 3;
    cout << climb(nums, k) << endl;

    return 0;

}