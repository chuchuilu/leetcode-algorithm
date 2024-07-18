#include<iostream>
#include<vector>
#include<queue>


using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs
        // 1.统计所有的烂橘子，并且入队
        // 2.然后bfs,广搜，然后每循环一次队列，分钟数递增，最后如果队列空，并且还有好橘子，就返回-1；
        int m = grid.size();
        int n = grid[0].size();
        int good_org = 0;
        queue<pair<int, int>>q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
              if(grid[i][j] == 1)   good_org++;
              else if(grid[i][j] == 2) q.push({i, j});
            }
        }

        vector<pair<int, int>>directions{{-1,0},{1,0},{0, -1},{0, 1}};

        if(good_org == 0)   return 0;
        int time = 0;
        while(good_org > 0 && !q.empty()){
            // 有好橘子才会感染，不然肯定会感染
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> bad_org = q.front();
                q.pop();
                for(int move = 0; move < 4; move ++){
                    int nx = bad_org.first + directions[move].first;
                    int ny = bad_org.second + directions[move].second;
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        good_org--;
                    }
                }  
            }
            time++;
            
        }
        return good_org > 0 ? -1 : time;
    }
};