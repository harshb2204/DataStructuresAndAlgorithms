#include <iostream>

using namespace std;


long long Mod(long long x, long long n, long long M) {
    if (n == 0)
        return 1;
    else if (n % 2 == 0) {
        long long y = Mod(x, n / 2, M);
        return (y * y) % M;
    } else {
        return (x % M * Mod(x, n - 1, M)) % M;
    }
}

int main() {
    long long x = 7;  // Base
    long long n = 3; // Exponent
    long long M = 5; // Modulus

    cout << "Result: " << Mod(x, n, M) << endl;

    return 0;
}
