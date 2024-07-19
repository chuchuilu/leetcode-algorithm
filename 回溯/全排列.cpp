#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(), false);
        dfs(nums, used);
        return ans;
    }

    void dfs(vector<int>&nums, vector<bool>& used){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }

};

int main(){
    Solution s;
    vector<int>nums{1,2,3};
    vector<vector<int>>res = s.permute(nums);
    for(auto r: res){
        for(int num: r){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}