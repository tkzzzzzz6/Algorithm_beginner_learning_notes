#include<iostream>
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
    int n;
    cin >> n;
    for(int i = 1;i<n;++i)
    {
        s += to_string(i);
    }
    cout << s[n-1] << '\n';
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
