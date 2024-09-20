#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

    vector<int> inDegree(v, 0);
    vector<int> result;

    // 计算每个节点的入度
    for (int i = 0; i < v; i++) {
        for (int neighbor : adjList[i]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    
    // 找出所有入度为 0 的节点
    for (int i = 0; i < v; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        // 遍历该节点的邻居，并减少其入度
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // 如果结果中的节点数量不等于 v，说明有环
    if (result.size() == v) {
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl << "Succeeded!" << endl;
    } else {
        cout << "Failed!" << endl;
    }

    return 0;
}
