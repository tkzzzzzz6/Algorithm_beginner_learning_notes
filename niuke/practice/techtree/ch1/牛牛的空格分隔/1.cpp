#include<iostream>
#include<iomanip>
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
    char ch;
    int a;
    double f;
    cin >> ch >> a >> f;
    cout << ch << ' ' << a << ' ' << fixed << setprecision(10) << f << endl;
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
