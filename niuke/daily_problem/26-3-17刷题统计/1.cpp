/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-15 00:10:38
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-18 23:37:10
 */
#include <iostream>
#include <vector>
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
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    int ans = ((a + b + c) - n - d) /2;
    cout << ans << endl;
}

int main()
{
    fastio;
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
