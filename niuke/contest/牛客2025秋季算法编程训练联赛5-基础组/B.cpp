#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m))
        return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int aI = a[8];                    // I题 = 第9题（下标 8）
    bool rule1 = 5LL * aI >= 4LL * m; // aI >= 0.8 * m  =>  5*aI >= 4*m（避免浮点）

    int greater_cnt = 0; // 严格大于 aI 的题目数量
    for (int x : a)
        if (x > aI)
            ++greater_cnt;
    bool rule2 = greater_cnt <= 2; // 排名前三：至多有两题严格比它多

    cout << (rule1 || rule2 ? "Yes" : "No") << '\n';
    return 0;
}
