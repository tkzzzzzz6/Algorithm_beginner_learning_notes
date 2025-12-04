#include<iostream>
#include<string>
#include<algorithm>
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
    int cnt = 0;
    sort(s.begin(),s.end());
    do{
        bool flag = true;
        for(int i =0;i<s.size();i++){
            if(s[i] == s[i+1])
            {
                flag = false;
                break;
            }
        }
        if(flag)++cnt;
    }while(next_permutation(s.begin(),s.end()));
    cout << cnt << endl;
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
