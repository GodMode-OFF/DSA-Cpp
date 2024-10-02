#include <iostream>
#include <vector>
#include <numeric> // for gcd

using namespace std;

// Function to compute the greatest common divisor
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to calculate number of distinct necklaces using Burnside's Lemma
int countNecklaces(int n, int k) {
    int count = 0;

    // Sum over all rotations
    for (int i = 0; i < n; i++) {
        count += pow(k, gcd(n, i));
    }

    // Divide by the number of rotations
    return count / n;
}

int main() {
    int n = 5; // number of beads
    int k = 3; // number of colors
    
    // Function call to count distinct necklaces
    int result = countNecklaces(n, k);
    
    // Output the result
    cout << "Number of distinct necklaces: " << result << endl;
    
    return 0;
}
