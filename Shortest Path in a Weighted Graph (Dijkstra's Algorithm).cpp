#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

// Function to find the shortest paths using Dijkstra's algorithm
void dijkstra(int src, int n, vector<vector<pii>>& adj) {
    // Distance vector to store the shortest distance to each node
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Min-heap priority queue to store {distance, node}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // If the popped node's distance is not up-to-date, skip it
        if (currentDist > dist[currentNode]) continue;

        // Explore neighbors of the current node
        for (auto& neighbor : adj[currentNode]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            // If a shorter path is found
            if (dist[currentNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[currentNode] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    // Output the shortest distance to each node
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << ": INF" << endl;
        } else {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // Create adjacency list
    vector<vector<pii>> adj(n);
    cout << "Enter the edges (u, v, w):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // If the graph is undirected, include this line.
    }

    int src;
    cout << "Enter the source node: ";
    cin >> src;

    // Run Dijkstra's algorithm from the source node
    dijkstra(src, n, adj);

    return 0;
}
