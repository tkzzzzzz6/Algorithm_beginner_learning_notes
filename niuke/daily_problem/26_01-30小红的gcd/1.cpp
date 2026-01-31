#include<bits/stdc++.h>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio \
ios::sync_with_stdio(false); \
cin.tie(0);

typedef long long ll;
const double PI = 3.1415926;

ll gcd(ll a,ll b){
    while(b!=0){
        ll t = a%b;
        a = b;
        b = t;
    }
    return a;
}

il void solve(){
    int n;cin >> n;
    int n1 = n;
    ll g = 0;

    for(int i = 0;i<n;++i){
        ll x;cin >> x;
        g = gcd(g,x);
    }
    cout << 1LL * n * g << endl;
}

int main()
{
    fastio;
    
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
