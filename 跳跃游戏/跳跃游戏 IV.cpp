/*
给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。

每一步，你可以从下标 i 跳到下标 i + 1 、i - 1 或者 j ：

i + 1 需满足：i + 1 < arr.length
i - 1 需满足：i - 1 >= 0
j 需满足：arr[i] == arr[j] 且 i != j
请你返回到达数组最后一个元素的下标处所需的 最少操作次数 。

注意：任何时候你都不能跳到数组外面。
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)  return 0;
        unordered_map<int, vector<int>>mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        vector<int>dist(n, INT_MAX);
        dist[0] = 0;
        q.push(0);
        int ans = 0;
        while(!q.empty()){
            int index = q.front();
            int step = dist[index];
            q.pop();
            if(index == n - 1)  return step;
            if(index + 1 < n && dist[index + 1] == INT_MAX){
                dist[index + 1] = step + 1;
                q.push(index + 1);
            }

            if(index - 1 >= 0 && dist[index - 1] == INT_MAX){
                dist[index - 1] = step + 1;
                q.push(index - 1);
            }
            vector<int>list = mp[arr[index]];
            for(auto key: list){
                if(dist[key] == INT_MAX){
                    q.push(key);
                    dist[key] = step + 1; 
                }
            }
            mp.erase(arr[index]);
        }
        return -1;
    }
};