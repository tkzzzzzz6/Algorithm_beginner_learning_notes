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
    int max_val = -inf, min_val = inf;
    for (int i = 0; i < n;++i)
    {
        int x;
        cin >> x;
        max_val = max(max_val,x);
        min_val = min(min_val, x);
    }
    cout << max_val - min_val << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    
    solve();

    return 0;
}