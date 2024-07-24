#include<iostream>
#include<vector>

using namespace std;


class Solution{
public:
    vector<vector<int>>ans;
    vector<int>path;
    vector<vector<int>> combine(vector<int>&nums){
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>&nums, int startIdx){
        ans.push_back(path);
        for(int i = startIdx; i < nums.size(); i++){
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }

    }

};

int main(){
    Solution combine;
    vector<int>nums{{1,2,3,4}};
    vector<vector<int>>ans = combine.combine(nums);
    for(const auto& list: ans){
        for(int num: list) cout << num << " ";
        cout << endl;
    }

    return 0;
}