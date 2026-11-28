#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
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
    vector<int> i(4,0);
    string s;
    cin >> s;
    for(char c:s)
    {
        if(islower(c))
            ++i[0];
        else if(isupper(c))
            ++i[1];
        else if(isdigit(c))
            ++i[2];
        else
            ++i[3];
    }
    int ans = 0;
    for(int j = 0;j<4;++j)
    {
        if(i[j] == 1)
        {
            if(j == 0 || j == 1)
            {
                ans += 25;
            }
            else if(j == 2)
            {
                ans += 9;
            }
            else
            {
                ans += 3;
            }
            continue;
        }
        ans += i[j] * 65;
    }
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
