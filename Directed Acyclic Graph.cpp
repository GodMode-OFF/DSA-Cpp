#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

// Function to perform topological sort using DFS
void topologicalSort(int v, vector<bool>& visited, stack<int>& Stack, const vector<vector<pair<int, int>>>& adj) {
    visited[v] = true;

    // Visit all the adjacent vertices
    for (const auto& neighbor : adj[v]) {
        int nextVertex = neighbor.first;
        if (!visited[nextVertex]) {
            topologicalSort(nextVertex, visited, Stack, adj);
        }
    }

    // Push current vertex to stack after all adjacent vertices are visited
    Stack.push(v);
}

// Function to find the longest path in a DAG
void findLongestPath(int start, int n, const vector<vector<pair<int, int>>>& adj) {
    stack<int> Stack;
    vector<bool> visited(n, false);

    // Perform topological sort
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            topologicalSort(i, visited, Stack, adj);
        }
    }

    // Initialize distances to all vertices as negative infinity
    vector<int> dist(n, INT_MIN);
    dist[start] = 0;

    // Process vertices in topological order
    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();

        // Update distances of all adjacent vertices of u
        if (dist[u] != INT_MIN) {
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight > dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Print the longest distances from the start vertex
    cout << "Longest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MIN) {
            cout << "Vertex " << i << ": -∞\n";
        } else {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices (n) and edges (m): ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    cout << "Enter the edges (u, v, weight) format:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].emplace_back(v, weight);
    }

    int start;
    cout << "Enter the start vertex: ";
    cin >> start;

    findLongestPath(start, n, adj);

    return 0;
}
