#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;

// Function to solve TSP using dynamic programming with bitmasking
int tsp(int mask, int pos, vector<vector<int>>& dist, vector<vector<int>>& dp) {
    int n = dist.size();

    // If all cities have been visited, return the distance to return to the origin
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    // If this subproblem has already been solved, return the result
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int minCost = INF;

    // Try visiting all unvisited cities and choose the minimum cost path
    for (int city = 0; city < n; ++city) {
        if ((mask & (1 << city)) == 0) {
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp);
            minCost = min(minCost, newCost);
        }
    }

    dp[mask][pos] = minCost;
    return minCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    // Initialize the dp table with -1
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    // Start the TSP from city 0 with only city 0 visited (mask = 1)
    int result = tsp(1, 0, dist, dp);

    cout << "The minimum cost to complete the TSP is: " << result << endl;

    return 0;
}
