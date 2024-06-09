#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ����ͼ�Ľṹ
class Graph {
    int V; // ͼ�Ķ�������
    vector<vector<int>> adj; // �ڽӱ�

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // ��ӱ�
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
    Graph g(4); // ����һ������4�������ͼ

    // ��ӱ�
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal (starting from vertex 2): ";
    g.DFS(2); // �Ӷ���2��ʼ����������ȱ���

    return 0;
}
