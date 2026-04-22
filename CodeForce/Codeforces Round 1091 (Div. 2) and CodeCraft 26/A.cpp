#include <iostream>
#include <vector>
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
    int n,k;
    cin >> n >> k;
    long long current_sum = 0;
    for(int i = 0;i<n;++i){
        int x;
        cin >> x;
        current_sum += x;
    }

    if(((current_sum & 1) == 1) || ((n*k) & 1) != 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

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
