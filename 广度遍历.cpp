#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// 定义图的结构
class Graph {
    int V; // 图的顶点数量
    vector<vector<pair<int, int>>> adj; // 邻接表

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // 添加边
    void addEdge(int u, int v, int w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w }); // 如果是有向图，则删除这一行
    }

    // Dijkstra算法
    void Dijkstra(int src) {
        vector<int> dist(V, INF);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, src });

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });
                }
            }
        }

        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }
};

int main() {
    Graph g(5); // 创建一个包含5个顶点的图

    // 添加边
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 3);

    g.Dijkstra(0); // 从顶点0开始计算最短路径

    return 0;
}
