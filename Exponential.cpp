#include <bits/stdc++.h>
using namespace std;

// O(N) power
long long powerON(long long x, long long n) {
    long long res = 1;
    for (long long i = 0; i < n; i++) res *= x;
    return res;
}

// O(log N) power (fast exponentiation)
long long powerOlogN(long long x, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

int main() {
    long long x = 2, n = 10;
    cout << "O(N): " << powerON(x, n) << endl;
    cout << "O(logN): " << powerOlogN(x, n) << endl;
    return 0;
}
