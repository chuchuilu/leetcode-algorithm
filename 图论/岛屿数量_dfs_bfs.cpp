#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    // 标记陆地
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
        
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0'; // 标记为访问过

        // 定义四个方向，分别是上、下、左、右
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // 遍历四个方向
            for (auto& d : directions) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1') {
                    q.push({nx, ny});
                    grid[nx][ny] = '0'; // 标记为访问过
                }
            }
        }
    }

        // 岛屿数量 bfs 陆地‘1’ 水 ‘0’
    void bfs(vector<vector<char>>&grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;
        q.push({i, j});
        grid[i][j] = '0';
        vector<pair<int, int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty())
        {
                auto [x, y] = q.front();
                q.pop();
                for(int k = 0; k < 4; k++){
                    int dx = x + directions[k].first;
                    int dy = y + directions[k].second;
                    if(dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == '1'){
                        grid[dx][dy] = '0';
                        q.push({dx, dy});
                    }
                }
        }
        
    }
};


int main(){
    Solution* s = new Solution();
    vector<vector<char>>grid{{'1','0','1','1','0','1','1'},{'0','1','1','0','0','1','0'},{'1','0','1','1','0','1','1'},{'1','0','0','0','0','0','0'},{'1','1','1','1','1','1','1'}};
    cout << s -> numIslands(grid) << endl;

}