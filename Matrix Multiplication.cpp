#include <iostream>
using namespace std;

int main() {
    int row1, column1, row2, column2;

    // Assuming matrix dimensions are provided by the user
    // For example purposes, you would ask for user input or use fixed dimensions
    cout << "Enter rows and columns for the first matrix: ";
    cin >> row1 >> column1;

    cout << "Enter rows and columns for the second matrix: ";
    cin >> row2 >> column2;

    // Ensure that column1 == row2 for valid matrix multiplication
    if(column1 != row2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    // Declare the matrices
    int m1[row1][column1], m2[row2][column2], result[row1][column2];

    // Initialize the result matrix to 0
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < column2; j++) {
            result[i][j] = 0;
        }
    }

    // Input values for the first matrix
    cout << "Enter elements of the first matrix:\n";
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < column1; j++) {
            cin >> m1[i][j];
        }
    }

    // Input values for the second matrix
    cout << "Enter elements of the second matrix:\n";
    for(int i = 0; i < row2; i++) {
        for(int j = 0; j < column2; j++) {
            cin >> m2[i][j];
        }
    }

    // Matrix multiplication logic
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < column2; j++) {
            for(int k = 0; k < column1; k++) {  // or row2 since column1 == row2
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // Display the result matrix
    cout << "Resultant matrix after multiplication:\n";
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < column2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
