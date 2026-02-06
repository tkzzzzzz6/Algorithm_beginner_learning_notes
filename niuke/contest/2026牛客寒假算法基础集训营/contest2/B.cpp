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
    int n;cin >> n;
    vector<ll> a(n+1);
    ll mx = 0;
    for(int i = 1;i<=n;++i){
        cin >> a[i];
        mx = max(a[i],mx);
    }

    ll cnt = 0;
    for(int i = 1;i<=n;++i){
        if(a[i] == mx)++cnt;
    }

    string s;
    s.reserve(n);

    if((cnt & 1) == 1){
        for(int i = 1;i<=n;++i)s.pb(a[i] == mx ? '1' : '0');
    }else{
        for(int i = 1;i<=n;++i)s.pb(a[i] == mx ? '0' : '1');
    }

    cout << s << endl;
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
