#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;

        // L = bit length of n, so that 2^L > n
        int L = 64 - __builtin_clzll(n); // n>=1

        long long x = n << L;
        long long y = x + n;

        cout << x << " " << y << "\n";
    }
    return 0;
}
