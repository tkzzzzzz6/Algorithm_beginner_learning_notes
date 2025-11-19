#include <bits/stdc++.h>
using namespace std;

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
        cin >> n;
        string s;
        cin >> s;

        int L = 0, R = 0, U = 0, D = 0;
        for (char c : s)
        {
            if (c == 'L')
                ++L;
            else if (c == 'R')
                ++R;
            else if (c == 'U')
                ++U;
            else if (c == 'D')
                ++D;
        }

        int ans = 1; // 至少有原点

        // 1. 只有水平运动
        if (U + D == 0)
        {
            ans = max(L, R) + 1;
        }
        // 2. 只有竖直运动
        else if (L + R == 0)
        {
            ans = max(U, D) + 1;
        }
        // 3. 横纵都有
        else
        {
            int total = L + R + U + D;
            bool hori_balanced = (L > 0 && R > 0 && L == R);
            bool vert_balanced = (U > 0 && D > 0 && U == D);

            if (hori_balanced && vert_balanced)
            {
                // 两个方向都完全平衡：一定至少有一次走到旧位置
                ans = total; // 最多 n 个不同位置
            }
            else
            {
                // 否则可以构造简单路径，每步访问新位置
                ans = total + 1; // 最多 n+1 个不同位置
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
