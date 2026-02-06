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
    int m,n;cin >> n >> m;

    vector<vector<int>> g(n+1);
    vector<int> deg(n+1,0);

    for(int i = 0;i<m;++i){
        int u,v;cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        ++deg[u];++deg[v];
    }

    vector<int> uniq;
    uniq.reserve(n);

    for(int i = 1;i<=n;++i)uniq.pb(deg[i]);
    sort(uniq.begin(),uniq.end());
    uniq.erase(unique(uniq.begin(),uniq.end()),uniq.end());
    int k = (int)uniq.size();

    vector<vector<int>> bucket(k);
    bucket.reserve(k);
    for(int i = 1;i<=n;++i){
        int idx = (int)(lower_bound(uniq.begin(),uniq.end(),deg[i])-uniq.begin());
        bucket[idx].pb(i);
    }

    vector<int> ans(n+1,-1);
    if(k == 1){
        for(int i = 1;i<=n;++i){
            cout << -1 << (i == n ? endl : ' ');
        }
        return 0;
    }

    vector<int> sources;
    sources.reserve(n);

    for(int t = k -1;t>=1;--t){
        for(auto v:bucket[t])
            sources.pb(v);

        
    }
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
