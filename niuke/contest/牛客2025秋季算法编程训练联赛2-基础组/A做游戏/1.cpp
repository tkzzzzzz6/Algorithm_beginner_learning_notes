#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    // 贪心策略：
    // 牛牛的石头(a) 对 牛可乐的剪刀(y) -> 赢 min(a, y) 局
    // 牛牛的剪刀(b) 对 牛可乐的布(z)   -> 赢 min(b, z) 局
    // 牛牛的布(c)   对 牛可乐的石头(x) -> 赢 min(c, x) 局

    ll win_cnt = min(a, y) + min(b, z) + min(c, x);

    cout << win_cnt << endl;

    return 0;
}