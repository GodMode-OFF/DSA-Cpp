#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing a number is valid
bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; ++i) {
        // Check the row and column
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
        // Check the 3x3 sub-box
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
            return false;
        }
    }
    return true;
}

// Backtracking function to solve the Sudoku
bool solveSudoku(vector<vector<char>>& board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == '.') {
                // Try placing numbers 1 to 9
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        // Recursively solve for the next cell
                        if (solveSudoku(board)) {
                            return true;
                        }
                        // Backtrack if the placement leads to no solution
                        board[row][col] = '.';
                    }
                }
                // If no valid number can be placed, return false
                return false;
            }
        }
    }
    return true;
}

// Function to print the Sudoku board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter the Sudoku board (use '.' for empty cells):\n";
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board)) {
        cout << "Solved Sudoku board:\n";
        printBoard(board);
    } else {
        cout << "No solution exists for the given Sudoku board.\n";
    }

    return 0;
}
