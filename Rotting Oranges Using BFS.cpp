#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q; // Queue to hold coordinates of rotten oranges
    int freshCount = 0, minutes = 0;

    // Initialize the queue with all rotten oranges and count fresh oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    // If there are no fresh oranges, return 0 (no time needed)
    if (freshCount == 0) return 0;

    // Directions array for up, down, left, right moves
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Perform BFS from all initial rotten oranges
    while (!q.empty()) {
        int size = q.size();
        bool hasRotten = false; // Track if any fresh oranges rot in this minute

        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();

            // Spread rot in all four directions
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                // If within bounds and the orange is fresh, rot it
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;  // Mark as rotten
                    freshCount--;
                    q.push({nx, ny});
                    hasRotten = true;
                }
            }
        }

        // Only increase minutes if at least one orange rotted
        if (hasRotten) minutes++;
    }

    // If there are still fresh oranges, return -1; otherwise, return the minutes taken
    return (freshCount == 0) ? minutes : -1;
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the grid values (0 for empty, 1 for fresh orange, 2 for rotten orange):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = orangesRotting(grid);
    if (result == -1) {
        cout << "Not all oranges can rot." << endl;
    } else {
        cout << "Minimum minutes to rot all oranges: " << result << endl;
    }

    return 0;
}
