#include"bits/stdc++.h"
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
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    
    int ans = 1e9;
    // 枚举使用烈焰风暴的次数k
    int max_k = max((a + y - 1) / y, (b + y - 1) / y) + 1;
    
    for(int k = 0; k <= max_k; k++){
        // 计算使用k次烈焰风暴后的剩余血量
        int rem_a = max(0, a - k * y);
        int rem_b = max(0, b - k * y);
        
        // 如果两只都死了
        if(rem_a == 0 && rem_b == 0){
            ans = min(ans, k);
            continue;
        }
        
        // 计算需要额外火球术的次数
        int fireball_needed = 0;
        if(rem_a > 0 && rem_b > 0){
            // 两只都活着，需要分别击杀
            fireball_needed = (rem_a + x - 1) / x + (rem_b + x - 1) / x;
        } else if(rem_a > 0){
            // 只有第一只活着
            fireball_needed = (rem_a + x - 1) / x;
        } else if(rem_b > 0){
            // 只有第二只活着
            fireball_needed = (rem_b + x - 1) / x;
        }
        
        ans = min(ans, k + fireball_needed);
    }
    
    cout << ans << endl;
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
