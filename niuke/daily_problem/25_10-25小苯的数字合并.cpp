// 不妨将第i个数是否与i+1合并设为一种状态，很明显有n-1种状态
// 每种状态都有合并和不合并两种情况，那么一共就有2的n-1次方种可能
#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353

// 快速幂算法
long long q(long long a,long long b) {
    long long ans = 1;
    while(b>0) {
        if(b&1)ans = a*ans%MOD; //判断b是否为奇数
        b = b>>1;
        a = a*a%MOD;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;cin >> t;long long n,x;
    while(t--) {
        cin >> n;
        for(int i = 0;i<n;i++) {
            cin >> x;
        }
        cout << q(2,n-1) <<'\n';
    }
}
