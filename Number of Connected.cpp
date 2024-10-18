#include <iostream>
#include <vector>
using namespace std;

// Find the root of a node with path compression
int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

// Union function to merge two sets
void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        // Union by rank to keep the tree flat
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Function to find the number of connected components
int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> parent(n);
    vector<int> rank(n, 0);

    // Initialize each node's parent to itself
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    // Process each edge and union the sets of its two nodes
    for (const auto& edge : edges) {
        unionSets(parent, rank, edge[0], edge[1]);
    }

    // Count the number of unique roots to determine the number of components
    int components = 0;
    for (int i = 0; i < n; ++i) {
        if (find(parent, i) == i) {
            components++;
        }
    }

    return components;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes (n) and edges (m): ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges (u, v):\n";
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int result = countComponents(n, edges);
    cout << "The number of connected components is: " << result << endl;

    return 0;
}
