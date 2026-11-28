#include <algorithm>
#include <iostream>
#include <vector>
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-04 16:52:07
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-04 16:52:13
 */
#include <bits/stdc++.h>
#include <queue>
using namespace std;

using ll = long long;

struct p{
    ll x,h;

    bool operator <(const p& other)const{
        return x<other.x;
    }
};

int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr);
    ll T;cin >> T;
    while(T--){
        ll n,m;
        cin >> n >> m;
        vector<p>a(n);

        for(ll i = 0;i<n;++i){
            cin >> a[i].h;
        }

        for(ll i = 0;i<n;++i){
            cin >> a[i].x;
        }

        sort(a.begin(),a.end());

        priority_queue<ll> q;
        ll t = 1;
        ll cmp = a[0].x + a[0].h;
        for(ll i = 0;i<n;++i){
            if(i == n-1){
                q.push(t);
                break;
            }
            if(cmp >= a[i+1].x){
                ++t;
                cmp=max(a[i+1].x+a[i+1].h,cmp);
            }else{
                q.push(t);
                t = 1;
                cmp = a[i+1].x+a[i+1].h;
            }
        }

        ll i = 0,ans = 0;
        while(!q.empty()&&i<m){
            ans += q.top();
            q.pop();
            ++i;
        }

        ans = min(ans,n);
        cout << ans << '\n';
    }
    return 0;
}
