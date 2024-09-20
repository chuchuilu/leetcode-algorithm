#include <iostream>
#include <vector>

using namespace std;

// DFS 递归函数，返回是否有环
bool dfs(int node, vector<vector<int>>& adjList, vector<int>& visited) {
    // 标记当前节点为正在访问
    visited[node] = 1;

    // 遍历邻居节点
    for (int neighbor : adjList[node]) {
        // 如果邻居节点未被访问，继续递归
        if (visited[neighbor] == 0) {
            if (dfs(neighbor, adjList, visited)) {
                return true;  // 如果发现环，则返回 true
            }
        }
        // 如果邻居节点正在被访问，说明存在环
        else if (visited[neighbor] == 1) {
            return true;
        }
    }

    // 标记当前节点为已访问
    visited[node] = 2;
    return false;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adjList(v);

    // 读取图的边
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adjList[u].push_back(w);
    }

    vector<int> visited(v, 0); // 标记节点的访问状态

    // 对每个节点进行 DFS
    bool hasCycle = false;
    for (int i = 0; i < v; i++) {
        if (visited[i] == 0) {
            if (dfs(i, adjList, visited)) {
                hasCycle = true;
                break;
            }
        }
    }

    // 输出结果
    if (hasCycle) {
        cout << "Graph has a cycle!" << endl;
    } else {
        cout << "Graph has no cycle!" << endl;
    }

    return 0;
}
