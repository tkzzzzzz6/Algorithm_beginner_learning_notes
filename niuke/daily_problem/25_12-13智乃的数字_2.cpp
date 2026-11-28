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

// 一个长度为 7 的周期数组，用于取模定位
vector<int> arr = {3, 5, 9, 15, 21, 25, 27};

il void solve() {
    long long k;
    cin >> k;
    // 使用 1-based 输入，转换为 0-based 索引
    --k;
    if (k < 0) {
        // 非法输入保护：当输入为 0 或负数时，输出第一个元素
        cout << arr[0] << endl;
        return;
    }
    long long t1 = k / 7;                                   // 周期数
    long long r2 = k % 7;                                   // 周期内偏移
    long long ans = t1 * 30 + arr[static_cast<size_t>(r2)]; // 防止溢出，使用 long long
    cout << ans << endl;
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
