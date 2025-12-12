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

int n,m;
string s;

il void solve(){
    int l,r;
    char c1,c2;
    cin >> l >> r >> c1 >> c2;
    if(c1 == c2)
        return;
    else{
        for(int i = l-1;i<r;++i)
        {
            if(s[i] == c1)
                s[i] = c2;
        }
    }
}

int main()
{
    fastio;
    
    cin >> n >> m;
    cin >> s;
    while(m--)
    {
        solve();
    }
    cout << s << "\n";
    
    return 0;
}
