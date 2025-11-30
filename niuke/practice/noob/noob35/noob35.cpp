#include<bits/stdc++.h>
#define il inline
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5+5, mod = 1e9+7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

// n*(n+1)/2

// 1,3,6,10

il void solve(){
    int n;
    cin >> n;
    int ans = 0;
    int sum = 0;
    for (int i = 1;i<=n;++i)
    {
        sum += i;
        ans += sum;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);

    solve();

    return 0;
}