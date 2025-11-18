#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K))
        return 0;

    // 预处理阶乘
    vector<long long> fact(N + 1, 1);
    for (int i = 1; i <= N; ++i)
    {
        fact[i] = fact[i - 1] * i; // 1*2*...*i
    }

    for (int qi = 0; qi < K; ++qi)
    {
        char op;
        cin >> op;

        if (op == 'P')
        {
            // 给编号，求对应排列
            long long A;
            cin >> A;
            long long idx = A - 1; // 变成 0-based

            // 当前还没被选过的数字，初始是 1..N
            vector<int> remain;
            remain.reserve(N);
            for (int i = 1; i <= N; ++i)
            {
                remain.push_back(i);
            }

            // 逐位确定
            for (int pos = 0; pos < N; ++pos)
            {
                long long block = fact[N - 1 - pos]; // 每种前缀对应的块大小
                long long t = idx / block;           // 当前位的系数
                idx %= block;

                int val = remain[(int)t]; // 第 t 个未使用的数字
                cout << val << (pos + 1 == N ? '\n' : ' ');
                remain.erase(remain.begin() + (int)t); // 删除，后面不能再用
            }
        }
        else if (op == 'Q')
        {
            // 给排列，求对应编号
            vector<int> perm(N);
            for (int i = 0; i < N; ++i)
            {
                cin >> perm[i];
            }

            vector<bool> used(N + 1, false);
            long long ans = 1; // 排名从 1 开始

            for (int i = 0; i < N; ++i)
            {
                int x = perm[i];
                // 统计比 x 小且没用过的数字个数
                int cnt = 0;
                for (int v = 1; v < x; ++v)
                {
                    if (!used[v])
                        ++cnt;
                }
                // 这些更小的选择会形成完整的块，每块大小 = 对应阶乘
                ans += (long long)cnt * fact[N - 1 - i];
                used[x] = true;
            }

            cout << ans << '\n';
        }
    }

    return 0;
}
