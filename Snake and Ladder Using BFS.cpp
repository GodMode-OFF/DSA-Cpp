#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int minMovesToReachEnd(vector<int>& board) {
    int n = board.size();
    queue<pair<int, int>> q;  // {position, moves}
    vector<bool> visited(n, false);

    q.push({0, 0}); // Start at the first cell with 0 moves
    visited[0] = true;

    while (!q.empty()) {
        auto [pos, moves] = q.front();
        q.pop();

        // If we reach the last cell, return the number of moves
        if (pos == n - 1) return moves;

        // Explore moves by rolling the die (1 through 6)
        for (int i = 1; i <= 6; i++) {
            int nextPos = pos + i;
            if (nextPos < n) {
                // Move to the destination if there's a snake or ladder
                if (board[nextPos] != -1) {
                    nextPos = board[nextPos];
                }

                // Add to queue if not visited
                if (!visited[nextPos]) {
                    visited[nextPos] = true;
                    q.push({nextPos, moves + 1});
                }
            }
        }
    }

    return -1; // If the end is not reachable
}

int main() {
    int n;
    cout << "Enter the size of the board (n x n): ";
    cin >> n;

    vector<int> board(n * n, -1);
    cout << "Enter the board values (-1 for no snake/ladder, destination index for snake/ladder):\n";
    for (int i = 0; i < n * n; i++) {
        cin >> board[i];
    }

    int result = minMovesToReachEnd(board);
    if (result == -1) {
        cout << "It's impossible to reach the last cell." << endl;
    } else {
        cout << "The minimum number of moves to reach the last cell is: " << result << endl;
    }

    return 0;
}
