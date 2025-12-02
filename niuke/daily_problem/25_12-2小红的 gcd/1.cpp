#include<iostream>
#include<string>
#define il inline
using namespace std;

#define fastio \
  ios::sync_with_stdio(false); \
  cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5+5, mod = 1e9+7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

il void solve(){
    string str;
    ll b;
    cin >> str;
    cin >> b;
    
    ll ans = 0;
    for(char c : str)
    {
        ans = (ans * 10 + (c - '0')) % b;
    }
    
    ll res = gcd(ans, b);
    cout << res << endl;
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
