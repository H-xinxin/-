#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 定义图的结构
class Graph {
    int V; // 图的顶点数量
    vector<vector<int>> adj; // 邻接表

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // 添加边
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // DFS
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

    void DFS(int v) {
        vector<bool> visited(V, false);
        DFSUtil(v, visited);
    }
};

int main() {
    Graph g(4); // 创建一个包含4个顶点的图

    // 添加边
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal (starting from vertex 2): ";
    g.DFS(2); // 从顶点2开始进行深度优先遍历

    return 0;
}
