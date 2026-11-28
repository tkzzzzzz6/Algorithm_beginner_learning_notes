#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> flag1, flag2;
vector<int> lg;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    flag1.resize(n + 5,1);
    flag2.resize(n + 5,0);
    lg.resize(n + 5,0);

    for (int i = 2; i <= n;++i)
    {
        lg[i] = lg[i >> 1] + 1;
    }

    for (int i = 1; i < n;++i)
    {
        int diff = n - i;
        if(lg[diff] + 1 <= k)
        {
            flag1[i] = 0;
            flag2[i] = 1;
            k -= lg[diff] + 1;
        }
        if(k == 0)
            break;
    }
    if(k > 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 1; i <= n;i++)
    {
        if(flag1[i])
        {
            cout << i << ' ';
        }
    }
    for (int i = n; i >= 1;i--)
    {
        if(flag2[i])
            cout << i << ' ';
    }
    cout << '\n';
    return 0;
}


