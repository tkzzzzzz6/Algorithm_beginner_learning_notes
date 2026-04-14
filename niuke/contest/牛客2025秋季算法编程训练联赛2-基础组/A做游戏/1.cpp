#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    // ̰Ĳԣ
    // ţţʯͷ(a)  ţֵļ(y) -> Ӯ min(a, y)
    // ţţļ(b)  ţֵĲ(z)   -> Ӯ min(b, z)
    // ţţĲ(c)    ţֵʯͷ(x) -> Ӯ min(c, x)

    ll win_cnt = min(a, y) + min(b, z) + min(c, x);

    cout << win_cnt << endl;

    return 0;
}
