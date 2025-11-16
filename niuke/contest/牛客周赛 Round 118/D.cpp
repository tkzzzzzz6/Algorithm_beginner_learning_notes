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
    multiset<int> s;
    for (int i = 0; i < n;++i)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    ll ans = 0,used = 0;
    for (auto it = s.rbegin(); it != s.rend();++it)
    {
        if(*it <= used)
            continue;
        ans += *it - used;
        ++used;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    

    solve();
    
    
    return 0;
}