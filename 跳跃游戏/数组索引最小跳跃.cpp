#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/*
问题描述
给定一个整数数组，每个元素表示在数组中的一个位置。你从索引 0 开始，目标是以最少的步数到达值为 -1 的元素。

每一步你可以选择：

向左移动一格（如果不在数组的起始位置）。
向右移动一格（如果不在数组的末尾）。
跳转到当前索引的值所指向的索引（如果这个值是一个有效的索引）。
示例
对于数组 [2, -1, 0, 4, 3]：

从索引 0 开始，值为 2。
你可以跳转到索引 2（当前值为 0），或者向右移动到索引 1。
如果选择跳转到索引 1，值为 -1，你到达了目标。
解法
这个问题通常可以用 广度优先搜索（BFS） 来解决。BFS 的核心思想是在搜索时尽量先遍历最近的节点，因此它可以保证最短路径。

伪代码示例
创建一个队列（queue）来存储当前的索引和步数。
创建一个集合（visited）来存储已经访问过的索引，防止重复访问。
从索引 0 开始，将 (0, 0) 放入队列，表示从索引 0 开始步数为 0。
循环遍历队列，取出每一个元素（index, steps），进行以下操作：
如果当前索引的值是 -1，返回当前的步数 steps。
检查当前索引的左右相邻的索引是否已经访问过，如果没有，将其加入队列和访问集合。
检查当前索引值所指向的索引是否已经访问过，如果没有，将其加入队列和访问集合。
如果队列为空且未找到目标，返回 -1。
*/

int minStepsToReachMinusOne(vector<int>& nums) {
    int n = nums.size();
    queue<pair<int, int>> q; // {current_index, steps}
    unordered_set<int> visited;
    
    q.push({0, 0});
    visited.insert(0);
    
    while (!q.empty()) {
        auto [index, steps] = q.front();
        q.pop();
        
        // 如果当前索引的值是 -1，返回步数
        if (nums[index] == -1) {
            return steps;
        }
        
        // 检查左边的索引
        if (index - 1 >= 0 && visited.find(index - 1) == visited.end()) {
            q.push({index - 1, steps + 1});
            visited.insert(index - 1);
        }
        
        // 检查右边的索引
        if (index + 1 < n && visited.find(index + 1) == visited.end()) {
            q.push({index + 1, steps + 1});
            visited.insert(index + 1);
        }
        
        // 检查跳转到的索引
        int jumpIndex = nums[index];
        if (jumpIndex >= 0 && jumpIndex < n && visited.find(jumpIndex) == visited.end()) {
            q.push({jumpIndex, steps + 1});
            visited.insert(jumpIndex);
        }
    }
    
    return -1; // 如果没有找到 -1
}

int main() {
    vector<int> nums = {2, -1, 0, 4, 3};
    cout << minStepsToReachMinusOne(nums) << endl; // 输出 1

    return 0;
}
