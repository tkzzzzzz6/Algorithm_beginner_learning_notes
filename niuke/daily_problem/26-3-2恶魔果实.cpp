/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-02 09:23:06
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-02 09:23:11
 */
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll mod = 1e4 + 7;

int main() {
    ll x, n;
    cin >> x >> n;
    vector<vector<bool>> to(10, vector<bool>(10, false));
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        to[a][b] = true;
    }
    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (to[i][k] && to[k][j]) {
                    to[i][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        to[i][i] = true;
    }

    vector<int> shu(10);
    for (int i = 0; i < 10; ++i) {
        int cnt = 0;
        for (int j = 0; j < 10; ++j) {
            if (to[i][j])
                ++cnt;
        }
        shu[i] = cnt;
    }

    ll ans = 1;
    while (x) {
        ans = ans * shu[x % 10] % mod;
        x /= 10;
    }
    cout << ans << endl;
}
