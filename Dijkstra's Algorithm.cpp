#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
using namespace std;

// Define a pair representing (distance, node)
typedef pair<int, int> pii;

// Function to find the shortest path avoiding obstacles
int shortestPathWithObstacles(int n, vector<vector<pii>>& adjList, int src, int dest, unordered_set<int>& obstacles) {
    // Min-heap priority queue to store (distance, node)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n, INT_MAX);  // Initialize distances to infinity
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        // Skip if this node is an obstacle
        if (obstacles.count(currNode)) {
            continue;
        }

        // If we reached the destination, return the distance
        if (currNode == dest) {
            return currDist;
        }

        // Explore neighbors
        for (auto& edge : adjList[currNode]) {
            int nextNode = edge.first;
            int weight = edge.second;

            // If the next node is not an obstacle and can be reached with a shorter distance
            if (!obstacles.count(nextNode) && currDist + weight < dist[nextNode]) {
                dist[nextNode] = currDist + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    // If destination is not reached, return -1
    return -1;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pii>> adjList(n);

    cout << "Enter the edges (u v w) where u and v are nodes (0-indexed) and w is the weight:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // If the graph is undirected
    }

    int src, dest;
    cout << "Enter the source and destination nodes: ";
    cin >> src >> dest;

    int numObstacles;
    cout << "Enter the number of obstacle nodes: ";
    cin >> numObstacles;
    unordered_set<int> obstacles;

    cout << "Enter the obstacle nodes (0-indexed): ";
    for (int i = 0; i < numObstacles; ++i) {
        int obstacleNode;
        cin >> obstacleNode;
        obstacles.insert(obstacleNode);
    }

    int result = shortestPathWithObstacles(n, adjList, src, dest, obstacles);

    if (result == -1) {
        cout << "There is no valid path from " << src << " to " << dest << " avoiding obstacles." << endl;
    } else {
        cout << "The shortest path from " << src << " to " << dest << " avoiding obstacles is: " << result << endl;
    }

    return 0;
}
