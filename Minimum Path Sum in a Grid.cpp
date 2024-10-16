#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the minimum path sum
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Create a dp table with the same size as the grid
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the top-left corner
    dp[0][0] = grid[0][0];

    // Initialize the first column
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Initialize the first row
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill in the rest of the dp table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // The bottom-right corner contains the minimum path sum
    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    cout << "Enter the number of rows (m) and columns (n): ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the grid values:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = minPathSum(grid);
    cout << "The minimum path sum is: " << result << endl;

    return 0;
}
