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

static const ll MOD = 998244353;

ll inv100 = modpow(100,MOD-2);


ll modpow(ll a,ll e){
    ll r = 1 % MOD;
    a %= MOD;
    while(e > 0){
        if(e & 1)r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

il void solve(){
    int C;
    cin >> C;
    vector<int> p(7);
    for(int i = 0;i<7;++i)cin >> p[i];
    vector<ll> on(7),off(7);
    for(int i = 0;i<7;++i){
        on[i] = (ll)p[i]*inv100 % MOD;
        off[i] = (1-on[i]+MOD)%MOD;
    }
    array<ll,10> prob{};
    for(int d = 0;d<=9;++d){
        ll pr = 1;
        for(int s = 0;s<7;++s){
            if(mask[d]&(1<<s))pr = pr*on[s]%MOD;
            else pr = pr*off[s]%MOD;
        }
        prob[d] = pr;
    }
    arr
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
