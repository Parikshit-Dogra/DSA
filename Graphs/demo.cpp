#include <iostream>
#include <queue>
#include <stdexcept>
#include <utility>
#include <vector>
using namespace std;

// Adjacency matrix representation of an undirected graph
vector<vector<int>> createGraph(
    int vertexCount,
    const vector<pair<int, int>>& edges
) {
    vector<vector<int>> graph(vertexCount, vector<int>(vertexCount, 0));

    for (const auto& [u, v] : edges) {
        if (u < 0 || u >= vertexCount || v < 0 || v >= vertexCount) {
            throw out_of_range("Edge contains an invalid vertex");
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    return graph;
}

vector<int> bfs(int start, const vector<vector<int>>& graph) {
    int vertexCount = static_cast<int>(graph.size());
    if (start < 0 || start >= vertexCount) {
        throw out_of_range("Starting vertex is invalid");
    }

    vector<bool> visited(vertexCount, false);
    vector<int> bfsOrder;
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfsOrder.push_back(node);

        for (int neighbor = 0; neighbor < vertexCount; ++neighbor) {
            if (graph[node][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfsOrder;
}

int main() {
    int vertexCount = 5;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}
    };

    vector<vector<int>> graph = createGraph(vertexCount, edges);
    int startNode = 0;
    vector<int> bfsResult = bfs(startNode, graph);

    cout << "BFS Order starting from node " << startNode << ": ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << '\n';

    return 0;
}