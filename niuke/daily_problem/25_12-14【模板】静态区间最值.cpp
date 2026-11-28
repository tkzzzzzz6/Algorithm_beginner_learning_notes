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

const int MAXN = 5e5 + 5;
const int LOGN = 20;

int n, q;
int a[MAXN];
int st_min[MAXN][LOGN];
int st_max[MAXN][LOGN];
int lg[MAXN];

void build_st() {
    lg[1] = 0;
    for (int i = 2; i <= n; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= n; ++i) {
        st_min[i][0] = a[i];
        st_max[i][0] = a[i];
    }

    for (int j = 1; j <= lg[n]; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query_min(int l, int r) {
    int k = lg[r - l + 1];
    return min(st_min[l][k], st_min[r - (1 << k) + 1][k]);
}

int query_max(int l, int r) {
    int k = lg[r - l + 1];
    return max(st_max[l][k], st_max[r - (1 << k) + 1][k]);
}

il void solve() {
    int op, l, r;
    cin >> op >> l >> r;
    if (op == 1) {
        cout << query_min(l, r) << endl;
    } else {
        cout << query_max(l, r) << endl;
    }
}

int main() {
    fastio;

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build_st();
    while (q--) {
        solve();
    }
}
