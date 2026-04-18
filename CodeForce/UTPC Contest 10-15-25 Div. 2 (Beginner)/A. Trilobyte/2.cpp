#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;

    //  k=0
    if (n % 8 == 0) {
        cout << 0 << '\n';
        return 0;
    }

    // ö k=1  99
    for (int k = 1; k <= 99; k++) {
        // ֻҪ3λ
        long long new_num;

        if (k < 10) {
            // 1λ
            new_num = (long long)n * 10 + k;
        }
        else {
            // 2λ
            new_num = (long long)n * 100 + k;
        }

        // ֻ3λȡģ1000
        if (new_num % 8 == 0) {
            cout << k << '\n';
            return 0;
        }
    }

    return 0;
}
