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
    int f[2] = {1,1};
    for (int i = 3; i <= n;++i)
    {
        int temp = f[0];
        f[0] = f[1];
        f[1] = temp + f[0];
    }
    cout << f[1] << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}