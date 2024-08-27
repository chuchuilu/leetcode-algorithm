class Solution {
public:
    string path;
    vector<string>ans;
    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return ans;
    }

    void dfs(int left, int right){
        if(left == 0 && right == 0){
            ans.push_back(path);
            return;
        }
        else{
            if(left > right || left < 0)    return;
            else{
                if(left > 0){
                    path.push_back('(');
                    dfs(left - 1, right);
                    path.pop_back();
                }
                if(right > 0){
                    path.push_back(')');
                    dfs(left, right - 1);
                    path.pop_back();
                }

            }
        }
 
    }
};