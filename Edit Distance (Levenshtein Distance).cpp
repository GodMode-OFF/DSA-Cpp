#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the minimum edit distance
int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    // Create a dp table of size (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize the first row and first column
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;  // Deleting all characters of word1 to match an empty word2
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;  // Inserting all characters of word2 to match an empty word1
    }

    // Fill the dp table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // Characters match, no new operations needed
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],      // Delete a character from word1
                                   dp[i][j - 1],      // Insert a character to word1
                                   dp[i - 1][j - 1]   // Replace a character in word1
                                  });
            }
        }
    }

    // The bottom-right cell contains the answer
    return dp[m][n];
}

int main() {
    string word1, word2;
    cout << "Enter the first word: ";
    cin >> word1;
    cout << "Enter the second word: ";
    cin >> word2;

    int result = minDistance(word1, word2);
    cout << "The minimum edit distance is: " << result << endl;

    return 0;
}
