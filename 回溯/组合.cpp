#include<iostream>
#include<vector>

using namespace std;


class Solution{
public:
    vector<vector<int>>ans;
    vector<int>path;
    vector<vector<int>> combine(int n, int k){
        dfs(n, k, 1);
        return ans;
    }

    void dfs(int n, int k, int startIdx){
        if(path.size() == k){
            ans.push_back(path);
            return;
        }
        for(int i = startIdx; i <= n; i++){
            path.push_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }

};

int main(){

    Solution combine;
    vector<vector<int>>ans = combine.combine(4, 2);

    for(const auto& list: ans){
        for(int num: list) cout << num << " ";
        cout << endl;
    }




    return 0;
}