#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
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

void to_lowercase(string &s)
{
    transform(s.begin(),s.end(),s.begin(),[](unsigned char c){return tolower(c);});
}

// 先将读取的字符串转化为对应的小写的字符串,
il void solve(){
    string s;
    cin >> s;
    for(char c:s)
    {
        c = tolower(c);
    }
    int n = s.size();
    int res = -1;
    to_lowercase(s);
    for(int i = 0;i<n-2;++i)
    {
        if(s.substr(i,3) == "bob")
        {
            res = i;
            cout << res << '\n';
            return;
        }
    }
    cout << res << '\n';
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
