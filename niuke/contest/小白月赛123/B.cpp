#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> pairs;
        ll ans = 0; // 使用 long long，避免溢出
        cin >> n;
        while (n--)
        {
            int x, y;
            cin >> x >> y;
            pairs.push_back({x, y});
        }
        // 按 b_i 降序排列，让 b_i 大的排在前面
        sort(pairs.begin(), pairs.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second > b.second; });
        // 第 i 个位置（从0开始）对应第 i+1 个位置（从1开始），所以减去的值是 i
        for (int i = 0; i < pairs.size(); i++)
        {
            ans += pairs[i].first - (ll)pairs[i].second * i;
        }
        cout << ans << endl;
    }

    return 0;
}