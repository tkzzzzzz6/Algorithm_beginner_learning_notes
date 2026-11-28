#include<iostream>
#include <utility>
#include <set>
#include <algorithm>
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

set<pair<int,int>> vp;

il void solve(){
    vp.clear();
    int q;
    cin >> q;
    int res = 1;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        pair<int,int> temp = make_pair(a,b);
        if(vp.empty())
        {
            vp.insert(temp);
            res = 2 + b -a;
        }
        else
        {
            auto it = vp.lower_bound(temp);
            if(it == vp.begin())
            {
                if(b < (*(vp.begin())).first)
                {
                    vp.insert(temp);
                    res = max(b-a+2,res);
                }
            }
            else if(it == vp.end())
            {
                it--;
                if(a>(*it).second)
                {
                    vp.insert(temp);
                    res = max(b-a+2,res);
                }
            }
            else
            {
                auto it1 = it;
                it--;
                int right = (*it1).first;
                int left = (*it).second;
                if(b<right&&a>left)
                {
                    vp.insert(temp);
                    res = max(b-a+2,res);
                }
            }
        }
        cout << res << '\n';
    }
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
