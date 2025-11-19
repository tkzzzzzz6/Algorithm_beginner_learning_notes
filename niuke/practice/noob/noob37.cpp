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
    int n;
    cin >> n;
    n = abs(n);
    int ans = 0;
    while(n >0){
        ans += n % 10;
        n /= 10;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}