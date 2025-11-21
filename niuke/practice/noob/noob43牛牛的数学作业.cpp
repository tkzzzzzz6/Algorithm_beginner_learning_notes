#include<bits/stdc++.h>
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
    int n;
    cin >> n;
    int max_val = -inf,min_val = inf;
    double mean = 0.0;
    vector<int> a(n);
    for (int i = 0; i < n;++i)
    {
        cin >> a[i];
        max_val = max(max_val, a[i]);
        min_val = min(min_val,a[i]);
        mean += a[i];
    }
    mean /= n;
    ll max_diff = max_val - min_val;
    long double variance = 0;
    for (auto i = a.begin(); i != a.end();++i)
    {
        variance += (*i - mean) * (*i - mean);
    }
    variance /= n;

    cout << max_diff << " " << setprecision(3) << fixed << variance << endl;
}

int main()
{
    fastio
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}