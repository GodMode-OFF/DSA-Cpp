#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Define a large number for initialization
const int INF = INT_MAX;

// Function to solve TSP using DP with bit masking
int tsp(int mask, int pos, int n, vector<vector<int>>& dist, vector<vector<int>>& dp) {
    // If all cities have been visited (mask is all 1's), return distance to starting city
    if (mask == (1 << n) - 1) {
        return dist[pos][0];  // Return to starting city
    }

    // If this state has already been computed, return its value
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    // Try visiting all unvisited cities and take the minimum
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {  // If city is not visited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, n, dist, dp);
            ans = min(ans, newAns);
        }
    }

    dp[mask][pos] = ans;
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Initialize DP table with -1
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    // Start from the first city (0) and mark it as visited (mask = 1)
    int result = tsp(1, 0, n, dist, dp);

    cout << "The minimum cost of visiting all cities is: " << result << endl;

    return 0;
}
