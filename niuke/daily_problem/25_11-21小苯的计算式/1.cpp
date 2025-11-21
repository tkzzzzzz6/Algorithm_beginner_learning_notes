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
    int n,c;
    cin >> n >> c;
    n = n - 3;
    int cnt = 0;
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < n-i;++j)
        {
            if(i + j == c)
            {
                ++cnt;
            }
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