#include <bits/stdc++.h>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

il void solve() {
    int a,b;
    cin >> a >> b;
    if(b == 0){
        cout << string(a,'0') << endl;
        return;
    }

    if(a == 1){
        cout << string(b,'1') << endl;
    }

    int r = min(b,a+1);
    vector<int> ones(r,b/r);
    for(int i = 0;i<b%r;++i)++ones[i];
    int g = r+1;
    vector<int> gap(a,0);
    int need = max(0,r-1);
    for(int i = 1;i<r-1;++i)gap[i] = 1;

    int rem0 = a - need;

    int base = rem0 /g;
    int extra = rem0 % g;
    for(int i = 0;i<g;++i){
        gap[i] += base + (i < extra ? 1:0);
    }

    string s;
    s.reserve(a+b);
    for(int i = 0 ;i<g;++i){
        s.append(gap[i],'0');
        if(i<r){
            s.append(ones[i],'1');
        }
    }
    cout << s << endl;
}

int main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
