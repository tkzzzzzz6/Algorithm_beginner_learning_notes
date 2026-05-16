/*
 * @acwing app=acwing.cn id=3198 lang=C++
 *
 * 3195. 有趣的数
 */

// @acwing code start
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 1010, MOD = 1e9 + 7;
int C[N][N];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (!j)
                C[i][j] = 1;
            else {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            }
        }
    }

    ll res = 0;

    for (int k = 2; k <= n - 2; ++k) {
        // % 和 * 同优先级
        res = ( res + (ll)C[n-1][k] * (k - 1) % MOD * (n - k - 1) % MOD) % MOD;
    }

    cout << res << endl;

    return 0;
}

// @acwing code end
