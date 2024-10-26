#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<bool>& visited, vector<pair<int, int>>& bridges, int& timer) {
    visited[node] = true;
    tin[node] = low[node] = timer++;
    
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;  // Skip the edge to the parent

        if (!visited[neighbor]) {
            // Explore the neighbor
            dfs(neighbor, node, adj, tin, low, visited, bridges, timer);
            // Update the low-link value of the current node
            low[node] = min(low[node], low[neighbor]);

            // Check if the edge is a bridge
            if (low[neighbor] > tin[node]) {
                bridges.push_back({node, neighbor});
            }
        } else {
            // Update low value for back edges
            low[node] = min(low[node], tin[neighbor]);
        }
    }
}

vector<pair<int, int>> findBridges(int n, vector<vector<int>>& adj) {
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<bool> visited(n, false);
    vector<pair<int, int>> bridges;
    int timer = 0;

    // Perform DFS from every unvisited node (for disconnected components)
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, -1, adj, tin, low, visited, bridges, timer);
        }
    }

    return bridges;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Because the graph is undirected
    }

    vector<pair<int, int>> bridges = findBridges(n, adj);

    if (bridges.empty()) {
        cout << "No bridges found in the graph." << endl;
    } else {
        cout << "Bridges in the graph are:\n";
        for (auto& bridge : bridges) {
            cout << bridge.first << " - " << bridge.second << endl;
        }
    }

    return 0;
}
