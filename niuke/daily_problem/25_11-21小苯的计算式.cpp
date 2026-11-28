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

// 获取数字的位数
int getNumlen(int num)
{
    if (num == 0)
    {
        return 1;
    }
    int len = 0;
    while (num > 0)
    {
        ++len;
        num /= 10;
    }
    return len;
}

il void solve()
{
    int n, c;
    cin >> n >> c;

    // 计算 C 的位数，得到 A+B 的位数和
    int len_c = getNumlen(c);
    n = n - len_c - 2; // 减去 C 的位数和两个符号('+' 和 '=')

    // 边界判断：A 和 B 至少各占 1 位
    if (n < 2)
    {
        cout << 0 << endl;
        return;
    }

    int cnt = 0;
    // 枚举 A 从 0 到 C，计算对应的 B，判断位数是否匹配
    for (int a = 0; a <= c; ++a)
    {
        int b = c - a;
        if (b < 0)
            continue;

        int len_a = getNumlen(a);
        int len_b = getNumlen(b);

        // 检查 A 和 B 的位数之和是否等于目标长度
        if (len_a + len_b == n)
        {
            ++cnt;
        }
    }

    cout << cnt << endl;
}

int main()
{
    fastio

        int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}