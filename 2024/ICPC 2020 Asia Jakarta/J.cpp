#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Modular exponentiation to calculate (base^exp) % mod
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Calculate the product of an arithmetic sequence efficiently
long long arithmetic_product(int base, int k, int N) {
    // Calculate the product of the terms (base + x * k) for x = 1 to N
    long long product = 1;
    for (int x = 1; x <= N; x *= 2) {
        long long term = (base + (x - 1) * k) % MOD;
        long long exponent = N / x;
        product = product * mod_exp(term, exponent, MOD) % MOD;
    }
    return product;
}

int main() {
    int base, k, N;
    cout << "Enter base, k, and N: ";
    cin >> base >> k >> N;

    cout << "The product is: " << arithmetic_product(base, k, N) << endl;
    return 0;
}
