#include<iostream>
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

int jc(int x)
{
    int ans = 1;
    for(int i = 1;i<=x;++i)
    {
        ans *= i;
    }
    return ans;
}

il void solve(){
    int n;
    cin >> n;
    int minn = n;
    int xi = 1;
    int yi =1;

    for(int x = 1;x<=13;++x)
    {
        if(x==2)
        {
            continue;
        }
        int jc_ = jc(x);
        int te = jc_-1;
        if(te == 0)
        {
            continue;
        }
        vector<int> arr;
        int y_1 = n/te;
        int y_2 = y_1+1;
        if(y_1 > 0)
        {
            arr.pb(y_1);
        }
        arr.pb(y_2);

        for(int i:arr)
        {
            if(i==2)
            {
                continue;
            }
            long long E = abs(i*te - n);

            if(E < minn)
            {
                minn = E;
                xi = x;
                yi = i;
            }
            if(minn == 0)
            {
                cout << xi << ' ' << yi << endl;
                return;
            }
        }
    }
    cout << xi << ' ' << yi << endl;
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
