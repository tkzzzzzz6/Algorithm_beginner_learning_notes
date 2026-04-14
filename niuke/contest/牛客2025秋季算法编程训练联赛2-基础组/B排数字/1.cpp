#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    // ͳַ '6'  '1' ĸ
    int cnt6 = 0, cnt1 = 0;
    for (char c : s)
    {
        if (c == '6')
            cnt6++;
        else if (c == '1')
            cnt1++;
    }

    // Ҫγ k  "616" ӴҪ (k+1)  '6'  k  '1'
    // ԣk <= cnt6 - 1  k <= cnt1
    // 𰸣min(cnt6 - 1, cnt1)

    int ans = 0;
    if (cnt6 >= 2 && cnt1 >= 1)
    {
        ans = min(cnt6 - 1, cnt1);
    }

    cout << ans << endl;

    return 0;
}
