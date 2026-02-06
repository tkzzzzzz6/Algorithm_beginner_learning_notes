/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-03 14:16:25
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-03 14:21:23
 */
#include <bits/stdc++.h>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

/* 
因为每个数都是不相同的,并且数组中所有元素的乘积与和相等,这种情况下只有
case 1: n = 1
case 2: n = 3
才行,
*/

il void solve() {
    int n; cin >> n;
    if(n == 1)cout << "YES\n1\n";
    else if(n == 3)cout << "YES\n1 2 3\n";
    else cout << "NO\n";

}

int main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
