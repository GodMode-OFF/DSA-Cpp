#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    bool isHamiltonianCycle(vector<int>& path, int pos) {
        // If all vertices are included in the path
        if (pos == V) {
            // And there's an edge from the last included vertex to the first vertex
            return find(adj[path[pos - 1]].begin(), adj[path[pos - 1]].end(), path[0]) != adj[path[pos - 1]].end();
        }

        // Try different vertices as next candidate in Hamiltonian Cycle
        for (int v = 1; v < V; v++) {
            if (isSafe(v, path, pos)) {
                path[pos] = v;

                if (isHamiltonianCycle(path, pos + 1)) {
                    return true;
                }

                // Backtrack
                path[pos] = -1;
            }
        }
        return false;
    }

    bool isSafe(int v, vector<int>& path, int pos) {
        // Check if this vertex is adjacent to the previously added vertex.
        if (find(adj[path[pos - 1]].begin(), adj[path[pos - 1]].end(), v) == adj[path[pos - 1]].end()) {
            return false;
        }

        // Check if the vertex has already been included.
        for (int i = 0; i < pos; i++) {
            if (path[i] == v) {
                return false;
            }
        }
        return true;
    }

    void findHamiltonianCycle() {
        vector<int> path(V, -1);

        // Start at vertex 0
        path[0] = 0;
        if (!isHamiltonianCycle(path, 1)) {
            cout << "No Hamiltonian Cycle exists" << endl;
        } else {
            cout << "Hamiltonian Cycle exists: ";
            for (int i = 0; i < V; i++) {
                cout << path[i] << " ";
            }
            cout << path[0] << endl; // Close the cycle
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findHamiltonianCycle();

    return 0;
}
