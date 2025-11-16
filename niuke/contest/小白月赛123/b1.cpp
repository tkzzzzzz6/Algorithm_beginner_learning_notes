#include<bits/stdc++.h>
#define il inline
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5+5, mod = 1e9+7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

il void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> pa(n);
    for(auto &[x,y]:pa)
        cin >> x >> y;
    sort(pa.begin(), pa.end(), [&](auto &a, auto &b)
         { return a.second > b.second; });
    ll ans = 0;
    for (ll i = 0; i < n;++i){
        auto [a,b] = pa[i];
        ans += a - b * i;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    
    int t = 0;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}