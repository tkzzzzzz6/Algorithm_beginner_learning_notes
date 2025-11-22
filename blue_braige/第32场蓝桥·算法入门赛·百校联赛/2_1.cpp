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
    vector<int> a(n);
    for (int i = 0; i < n;++i)
        cin >> a[i];

    sort(a.begin(), a.end());
    for (int i = 0; i < n;++i)
    {
        if(a[i] < i + 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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