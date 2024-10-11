#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, pair<int, int>> pi;

vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// Function to check if a move is within the grid bounds and valid
bool isValid(int x, int y, int n, int m, vector<vector<int>>& grid) {
    return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != -1);
}

int minCostPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    // Priority queue to store {cost, {x, y}}
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    
    // Start from the top-left corner (0, 0)
    pq.push({grid[0][0], {0, 0}});
    dist[0][0] = grid[0][0];
    
    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        
        // If we reached the bottom-right corner, return the cost
        if (x == n - 1 && y == m - 1) return cost;
        
        // Explore all 4 possible directions
        for (auto dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            
            if (isValid(newX, newY, n, m, grid)) {
                int newCost = cost + grid[newX][newY];
                // If a cheaper path is found, update and push to queue
                if (newCost < dist[newX][newY]) {
                    dist[newX][newY] = newCost;
                    pq.push({newCost, {newX, newY}});
                }
            }
        }
    }
    
    // If we reach here, there is no valid path to the bottom-right corner
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    int result = minCostPath(grid);
    cout << result << endl;
    
    return 0;
}
