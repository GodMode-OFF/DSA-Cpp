#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the Longest Common Subsequence (LCS)
int LCS(const string& A, const string& B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    return dp[n][m];
}

// Function to find the LCS between two circular strings
int circularLCS(string A, string B) {
    int n = A.size();
    
    // Double the string A to handle circularity
    string A_doubled = A + A;
    
    // Find the maximum LCS by comparing B with each n-length substring of A_doubled
    int maxLCS = 0;
    for (int i = 0; i < n; i++) {
        string sub_A = A_doubled.substr(i, n);
        maxLCS = max(maxLCS, LCS(sub_A, B));
    }
    
    return maxLCS;
}

int main() {
    string A = "abcde";
    string B = "cdeab";
    
    // Function call to find the LCS between two circular strings
    int result = circularLCS(A, B);
    
    // Output the result
    cout << "Longest Common Subsequence between two circular strings: " << result << endl;
    
    return 0;
}
