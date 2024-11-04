#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1; // Start or end is blocked

    // 8 possible movements: right, left, down, up, and 4 diagonals
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},
                                         {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    // BFS queue to store cells and their path lengths
    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1; // Mark start cell as visited by using path length

    while (!q.empty()) {
        auto [x, y] = q.front();
        int pathLength = grid[x][y];
        q.pop();

        // If we reach the bottom-right corner, return the path length
        if (x == n - 1 && y == n - 1) {
            return pathLength;
        }

        // Explore all 8 possible directions
        for (auto& [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                q.push({nx, ny});
                grid[nx][ny] = pathLength + 1; // Mark visited and set path length
            }
        }
    }

    return -1; // No path found
}

int main() {
    int n;
    cout << "Enter the size of the grid (n x n): ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the grid (0 for open, 1 for blocked):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = shortestPathBinaryMatrix(grid);
    if (result == -1) {
        cout << "No path to the destination." << endl;
    } else {
        cout << "The shortest path length is: " << result << endl;
    }

    return 0;
}
