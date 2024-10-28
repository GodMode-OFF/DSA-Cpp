#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestPalindromicSubsequence(const string& s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Every single character is a palindrome of length 1
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Build the dp table
    for (int length = 2; length <= n; ++length) { // length of substring
        for (int i = 0; i < n - length + 1; ++i) {
            int j = i + length - 1; // Ending index of the substring
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2; // Characters match
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // Characters don't match
            }
        }
    }

    // The length of the longest palindromic subsequence will be in dp[0][n-1]
    return dp[0][n - 1];
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = longestPalindromicSubsequence(s);
    cout << "The length of the longest palindromic subsequence is: " << result << endl;

    return 0;
}
