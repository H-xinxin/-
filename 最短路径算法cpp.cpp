#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

#define INF INT_MAX // 无穷大值

// 图的结构
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
        // 创建距离数组并初始化为无穷大
        vector<int> dist(V, INF);
        dist[src] = 0; // 源点到自身的距离为0

        // 创建优先队列，按照距离的升序排列
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, src }); // 将源点入队

        // 迭代遍历图中的顶点
        while (!pq.empty()) {
            int u = pq.top().second; // 获取距离最短的顶点
            pq.pop();

            // 遍历当前顶点的所有邻居
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first; // 邻居顶点的编号
                int weight = neighbor.second; // 边的权重

                // 如果通过当前顶点u到邻居顶点v的路径距离更短，则更新距离数组并将邻居顶点v入队
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });
                }
            }
        }

        // 输出最短距离
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }
};

// 生成随机图
void generateRandomGraph(Graph& g, int numVertices, int numEdges) {
    srand(time(nullptr)); // 设置随机种子

    for (int i = 0; i < numEdges; ++i) {
        int u = rand() % numVertices; // 随机选择起点
        int v = rand() % numVertices; // 随机选择终点
        int w = rand() % 10 + 1; // 随机生成边的权重，范围为1到10
        g.addEdge(u, v, w); // 添加边
    }
}

int main() {
    int choice;
    cout << "Enter 1 to generate a random graph and compute shortest paths using Dijkstra's algorithm.\n";
    cout << "Enter 0 to exit.\n";

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice == 1) {
            int numVertices, numEdges;
            cout << "Enter the number of vertices: ";
            cin >> numVertices;
            cout << "Enter the number of edges: ";
            cin >> numEdges;

            Graph g(numVertices); // 创建一个图
            generateRandomGraph(g, numVertices, numEdges); // 生成随机图

            int src;
            cout << "Enter the source vertex: ";
            cin >> src;

            g.Dijkstra(src); // 计算最短路径
        }
        else {
            cout << "Invalid choice. Please enter 0 or 1.\n";
        }
    }

    return 0;
}
