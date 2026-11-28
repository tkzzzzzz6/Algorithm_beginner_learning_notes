#include<vector>
#include<iostream>
#include<algorithm>
#define il inline
using namespace std;

#define pb push_back
#define fastio \
  ios::sync_with_stdio(false); \
  cin.tie(0);



const long long N = 5e5+5, mod = 1e9+7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;


vector<int> w;
vector<vector<int>>adj;
vector<vector<long long>> dp;

void dfs(int u,int p)
{
    dp[u][1] = w[u-1];
    dp[u][0] = 0;

    for(int v:adj[u])
    {
        if(v == p)
            continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

il void solve(){
    int n;
    cin >> n;
    w.resize(n);
    for(int i = 0;i<n;++i)
    {
        cin >> w[i];
    }
    if(n == 1)
    {
        cout << w[0] << endl;
        return;
    }
    adj.resize(n+1);
    vector<bool>has_parent(n+1,false);
    for(int i = 0;i<n-1;++i)
    {
        int boss,subordinate;
        cin >> boss >> subordinate;
        adj[boss].push_back(subordinate);
        adj[subordinate].push_back(boss);
        has_parent[subordinate] = true;
    }

    int root = -1;
    for(int i = 1;i<=n;++i)
    {
        if(!has_parent[i]){
            root = i;
            break;
        }
    }
    dp.assign(n+1,vector<long long>(2,0));
    dfs(root,-1);
    cout << max(dp[root][0],dp[root][1]) << endl;
    
}

int main()
{
    fastio
    
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
