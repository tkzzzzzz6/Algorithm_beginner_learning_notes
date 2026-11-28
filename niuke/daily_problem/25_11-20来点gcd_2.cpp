#include<bits/stdc++.h>
#define il inline
using namespace std;

#define pb push_back
#define fastio \
  ios::sync_with_stdio(false); \
  cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5+5, mod = 1e9+7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

il void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> cnt(n+1,0);
    int x;
    for (int i = 0; i < n;++i)
    {
        int a;
        cin >> a;
        ++cnt[a];
    }
    vector<bool> ans(n + 1, false);
    for (int i = 1; i <= n;++i)
    {
        int g = 0;
        for (int j = i; j <= n;j+=i)
        {
            if(cnt[j] > 0)
            {
                g = gcd(g, j);
                if(g == i)
                {
                    break;
                }
            }
        }
        if(g == i)
        {
            ans[i] = true;
        }
    }
    while(m--)
    {
        int x;
        cin >> x;
        if(x <= n && ans[x])
        {
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}

int main()
{
    fastio
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}