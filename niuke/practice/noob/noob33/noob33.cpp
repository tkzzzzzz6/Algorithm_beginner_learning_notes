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
    double sum = 0;
    for (int i = 0; i < n;++i)
    {
        sum += 1.0 / (i + 1);
    }
    cout << fixed << setprecision(6) << sum << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    
    solve();
    return 0;
}