#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        ll m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        // 特判：n = 1，长度为 1 天然严格递增，d = 0 即可
        if (n == 1)
        {
            cout << 0 << '\n';
            continue;
        }

        // 如果原数组已经严格递增，那么 d = 0 就行
        bool strictly_inc = true;
        for (int i = 1; i < n; ++i)
        {
            if (!(a[i] > a[i - 1]))
            {
                strictly_inc = false;
                break;
            }
        }
        if (strictly_inc)
        {
            cout << 0 << '\n';
            continue;
        }

        // 统计“不递增位置”的个数，并计算 Dmax
        // diff_i = a[i] - a[i-1] <= 0 的位置是“坏点”
        // C_i = 1 - diff_i = 1 + a[i-1] - a[i]
        // 当 d >= max_i C_i 时，每个坏点只需要 need_i = 1 次“增量”
        ll cntBad = 0;
        ll Dmax = 0; // 上界
        for (int i = 1; i < n; ++i)
        {
            ll diff = a[i] - a[i - 1];
            if (diff <= 0)
            {
                ++cntBad;
                ll C = 1 - diff; // = 1 + a[i-1] - a[i] >= 1
                if (C > Dmax)
                    Dmax = C;
            }
        }

        // 如果坏点数 > m，无论 d 多大都不可能（每个坏点至少需要 1 次操作）
        if (cntBad > m)
        {
            cout << -1 << '\n';
            continue;
        }

        // 接下来考虑 d > 0 的情况，答案一定在 [1, Dmax] 内
        // 并且 d = Dmax 一定可行（此时每个坏点 need_i = 1，总操作数 = cntBad <= m）

        auto check = [&](ll d) -> bool
        {
            ll ops = 0;
            for (int i = 1; i < n; ++i)
            {
                ll diff = a[i] - a[i - 1];
                if (diff >= 1)
                    continue;              // 本来就严格递增，不用管
                ll C = 1 - diff;           // 需要 d * (x_i - x_{i-1}) >= C
                ll need = (C + d - 1) / d; // ceil(C / d)
                ops += need;
                if (ops > m)
                    return false; // 提前剪枝
            }
            return ops <= m;
        };

        ll L = 1, R = Dmax, ans = Dmax;
        while (L <= R)
        {
            ll mid = (L + R) >> 1;
            if (check(mid))
            {
                ans = mid;
                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}