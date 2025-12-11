#include <bits/stdc++.h>
#define il inline
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

long long n, m, k;

/**
 * 计算在 n×m 矩阵中，有多少个元素的值 ≤ x
 * 矩阵第 i 行第 j 列的值为 i*j
 * @param x 阈值
 * @return 小于等于 x 的元素个数
 */
long long work(long long x) {
    long long res = 0;
    // 遍历每一行
    for (int i = 1; i <= n; ++i) {
        // 第 i 行中，满足 i*j <= x 的 j 有 x/i 个
        // 但 j 最大为 m，所以取 min(x/i, m)
        res += min(x / i, m);
        // 优化：如果 x/i == 0，后面的行更不可能有贡献
        if (x / i == 0)
            break;
    }
    return res;
}

il void solve() {
    cin >> n >> m >> k;
    // 二分查找第 k 小的元素
    // 搜索范围：[1, n*m]（矩阵中最小值为1，最大值为n*m）
    long long l = 1, r = n * m, ans = 0;
    while (l <= r) {
        // 防止溢出的中点计算方式
        long long mid = l + ((r - l) >> 1);
        // 如果小于等于 mid 的元素个数 >= k
        // 说明第 k 小的元素 <= mid，在左半部分继续搜索
        if (work(mid) >= k) {
            ans = mid;   // 记录可能的答案
            r = mid - 1; // 尝试找更小的值
        } else {
            // 否则第 k 小的元素在右半部分
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    fastio // 快速输入输出

        int t = 1;
    // cin >> t;  // 多组测试数据时取消注释
    while (t--) {
        solve();
    }

    return 0;
}
