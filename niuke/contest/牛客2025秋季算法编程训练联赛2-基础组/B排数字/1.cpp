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

    // 统计字符 '6' 和 '1' 的个数
    int cnt6 = 0, cnt1 = 0;
    for (char c : s)
    {
        if (c == '6')
            cnt6++;
        else if (c == '1')
            cnt1++;
    }

    // 要形成 k 个 "616" 子串，需要 (k+1) 个 '6' 和 k 个 '1'
    // 所以：k <= cnt6 - 1 且 k <= cnt1
    // 答案：min(cnt6 - 1, cnt1)

    int ans = 0;
    if (cnt6 >= 2 && cnt1 >= 1)
    {
        ans = min(cnt6 - 1, cnt1);
    }

    cout << ans << endl;

    return 0;
}