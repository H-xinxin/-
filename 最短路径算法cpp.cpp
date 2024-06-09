#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

#define INF INT_MAX // �����ֵ

// ͼ�Ľṹ
class Graph {
    int V; // ͼ�Ķ�������
    vector<vector<pair<int, int>>> adj; // �ڽӱ�

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // ��ӱ�
    void addEdge(int u, int v, int w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w }); // ���������ͼ����ɾ����һ��
    }

    // Dijkstra�㷨
    void Dijkstra(int src) {
        // �����������鲢��ʼ��Ϊ�����
        vector<int> dist(V, INF);
        dist[src] = 0; // Դ�㵽����ľ���Ϊ0

        // �������ȶ��У����վ������������
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, src }); // ��Դ�����

        // ��������ͼ�еĶ���
        while (!pq.empty()) {
            int u = pq.top().second; // ��ȡ������̵Ķ���
            pq.pop();

            // ������ǰ����������ھ�
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first; // �ھӶ���ı��
                int weight = neighbor.second; // �ߵ�Ȩ��

                // ���ͨ����ǰ����u���ھӶ���v��·��������̣�����¾������鲢���ھӶ���v���
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });
                }
            }
        }

        // �����̾���
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }
};

// �������ͼ
void generateRandomGraph(Graph& g, int numVertices, int numEdges) {
    srand(time(nullptr)); // �����������

    for (int i = 0; i < numEdges; ++i) {
        int u = rand() % numVertices; // ���ѡ�����
        int v = rand() % numVertices; // ���ѡ���յ�
        int w = rand() % 10 + 1; // ������ɱߵ�Ȩ�أ���ΧΪ1��10
        g.addEdge(u, v, w); // ��ӱ�
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

            Graph g(numVertices); // ����һ��ͼ
            generateRandomGraph(g, numVertices, numEdges); // �������ͼ

            int src;
            cout << "Enter the source vertex: ";
            cin >> src;

            g.Dijkstra(src); // �������·��
        }
        else {
            cout << "Invalid choice. Please enter 0 or 1.\n";
        }
    }

    return 0;
}
