#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;

    vector<int> a(t, 0);
    for (int i = 0; i < t; ++i)
    {
        cin >> a[i];
    }
    string ans = "";
    for (int i = 0; i < t; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] < a[i])
            {
                ++cnt;
            }
        }
        ans += to_string(cnt);
        if(i != t-1)
        {
            ans += ' ';
        }
    }
    cout << ans << endl;

    return 0;
}
