#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to generate all prime numbers up to n using Sieve of Eratosthenes
vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;

    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
            for (int i = p * 2; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return primes;
}

// Function to calculate the number of divisors of n!
int countDivisorsOfFactorial(int n) {
    vector<int> primes = sieve(n);
    long long divisors = 1;

    // For each prime, calculate its power in the factorization of n!
    for (int p : primes) {
        int count = 0;
        int power = p;
        while (power <= n) {
            count += n / power;
            power *= p;
        }
        divisors = divisors * (count + 1) % 1000000007; // To prevent overflow, take modulo
    }

    return divisors;
}

int main() {
    int n;
    cout << "Enter a number n to find the number of divisors of n!: ";
    cin >> n;

    int result = countDivisorsOfFactorial(n);
    cout << "The number of divisors of " << n << "! is: " << result << endl;

    return 0;
}
