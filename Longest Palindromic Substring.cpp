#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the longest palindromic substring
string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";

    // dp[i][j] will be true if the substring s[i:j+1] is a palindrome
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLength = 1; // Length of the longest palindrome found
    int start = 0; // Starting index of the longest palindrome

    // Every single character is a palindrome
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    // Check for two-character palindromes
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for palindromes longer than two characters
    for (int length = 3; length <= n; ++length) {
        for (int i = 0; i < n - length + 1; ++i) {
            int j = i + length - 1; // Ending index of the current substring
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLength = length;
            }
        }
    }

    // Return the longest palindromic substring
    return s.substr(start, maxLength);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = longestPalindrome(s);
    cout << "The longest palindromic substring is: " << result << endl;

    return 0;
}
