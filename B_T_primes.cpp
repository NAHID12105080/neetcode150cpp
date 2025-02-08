#include <bits/stdc++.h>
using namespace std;

const int MAX_LIMIT = 1000000;
vector<bool> isPrime(MAX_LIMIT + 1, true);

// Function to preprocess prime numbers using Sieve of Eratosthenes
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX_LIMIT; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_LIMIT; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// Function to check if a number is a T-prime (square of a prime)
bool isTPrime(long long num) {
    long long root = sqrt(num);
    return (root * root == num) && isPrime[root];
}

int main() {
    sieve(); // Precompute prime numbers
    
    int n;
    cin >> n;
    
    while (n--) {
        long long num;
        cin >> num;
        cout << (isTPrime(num) ? "YES" : "NO") << endl;
    }
    
    return 0;
}
