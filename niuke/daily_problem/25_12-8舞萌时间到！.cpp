#include<iostream>
#include<string>
#include<vector>
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
    string s;
    cin >> s;
    int len = s.size();
    vector<int> pre(len+1,0);
    int q;
    cin >> q;

    for(int i=0;s[i];++i)
    {
        int dx = 0;
        if(s[i] == 'P')
            dx = 3;
        else if(s[i] == 'p')
            dx = 2;
        else if(s[i] == 'G')
            dx = 1;
        // g和m默认dx = 0
        pre[i+1] = pre[i] + dx;
    }
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        int ans = pre[r] - pre[l-1];
        cout << ans << endl;
    }
}

int main()
{
    fastio
    
    int t = 1;
    while(t--)
    // cin >> t;
    {
        solve();
    }
    
    return 0;
}
