#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    string res = "";
    for(int i = n-1;i>=0;--i)
    {
        if(cnt % 3 == 0 && cnt > 0)
        {
            res += ',';
        }
        res += s[i];
        cnt++;
    }
    reverse(res.begin(),res.end());
    cout << res << '\n';
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
