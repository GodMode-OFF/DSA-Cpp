#include <iostream>
#include <vector>
using namespace std;

// Function to check if a queen can be placed at (row, col)
bool isSafe(vector<string>& board, int row, int col, int n) {
    // Check column for another queen
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

// Recursive function to solve N-Queens
void solveNQueens(int row, int n, vector<string>& board, vector<vector<string>>& solutions) {
    // If all queens are placed, add the current board configuration to solutions
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';  // Place queen
            solveNQueens(row + 1, n, board, solutions);  // Recur for the next row
            board[row][col] = '.';  // Backtrack and remove the queen
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of N:⬤
