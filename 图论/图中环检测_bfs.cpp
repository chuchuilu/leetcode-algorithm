#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adjList(v);
    vector<int> inDegree(v, 0);  // 记录每个节点的入度

    // 读取图的边
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adjList[u].push_back(w);
        inDegree[w]++;  // 计算入度
    }

    queue<int> q;

    // 将所有入度为 0 的节点加入队列
    for (int i = 0; i < v; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;  // 记录处理的节点数

    // 进行拓扑排序
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        // 遍历该节点的邻居，减少邻居节点的入度
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // 如果处理的节点数等于图的顶点数，则无环
    if (count == v) {
        cout << "Graph has no cycle!" << endl;
    } else {
        cout << "Graph has a cycle!" << endl;
    }

    return 0;
}
