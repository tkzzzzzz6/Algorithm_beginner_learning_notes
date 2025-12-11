#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
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
    vector<pair<char,int>> lenOption;
    for(int i = 0;i<4;++i)
    {
        string s;
        cin >> s;
        lenOption.push_back({(int)s.size(),s[0] });
    }
    sort(lenOption.begin(),lenOption.end());
    int L1 = lenOption[0].first;
    int L2 = lenOption[1].first;
    int L3 = lenOption[2].first;
    int L4 = lenOption[3].first;
    int flag = 0;
    if(L1 < L2 && L2 == L3 && L3 == L4)
    {
        flag = 1;
    }else if(L1 == L2 && L2 == L3 && L3 < L4)
    {
        flag = 2;
    }
    switch (flag){
        case 1:
            cout << lenOption[0].second << '\n';
            break;
        case 2:
            cout << lenOption[3].second << '\n';
            break;
        default:
            cout << 'C' << '\n';
            break;
    }    
}

int main()
{
    fastio
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
