/*
 * @Author: tkzzzzzz6
 * @Date: 2026-01-29 21:04:00
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-01-29 21:13:16
 */

#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define int long long
const int N = 10000005;
const int M = 1e9+7;

int n,a[N],Fac[N];

vector<pair<int,int>>yuna;

int qpow(int a,int b){
    int ret = 1;
    while(b){
        if(b&1)ret = ret*a%M;
        a = a*a%M;b>>=1;
    }
    return ret;
}

int inv(int x){
    return qpow(x,M-2);
}

int C(int a,int b){
    if(a<b)return 0;
    return Fac[a]*inv(Fac[b])%M*inv(Fac[a-b])%M;
}

void solve(){
    cin >> n;int st = 0;a[0] = 1000;a[n+1] = 1;
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=n+1;++i){
        if(a[i])yuna.push_back({st+1,i-1}),st = i;
    }
    int ans = 1;
    for(auto &[l,r]:yuna){
        if(l>r)continue;
        int w = a[l-1]-a[r+1]+1,h=r-l+1;
        ans = ans*C(w+h-1,h)%M;
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    Fac[0] = 1;
    for(int i = 1;i<=N-1;++i){
        Fac[i] = Fac[i-1]*i%M;
    }
    solve();
    return 0;
}
