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
    int n,k;
    cin >> n >> k;

    string s;
    cin >> s;

    auto cnt = vector(k,vector<int>(26));

    for(int i = 0;i<n;++i)
    {
        cnt[i%k][s[i]-'a']++;
    }
    int ans = 0;
    for(int i = 0;i<k;++i)
    {
        int maxCnt = 0;

        for(int j = 0;j<26;++j)
        {
            maxCnt = std::max(maxCnt,cnt[i][j]);
        }
        int total = (i < n%k)?(n/k+1):(n/k);
        ans += total - maxCnt;
    }
    cout << ans << '\n';
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
