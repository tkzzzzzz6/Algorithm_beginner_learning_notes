#include<bits/stdc++.h>
#define il inline
#define endl '\n'
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
    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];

    ll ans = a[1] + k;

    ans = max(ans,a[n]+k);

    for(int i = 2;i<=n;++i){
        ans = max(ans,a[i-1]+a[i]);
    }

    cout << ans << endl;

}

int main()
{
    fastio;
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
