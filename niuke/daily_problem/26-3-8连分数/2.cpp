/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-09 00:02:35
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-09 00:04:41
 */
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

void murname(){
    ll p,q,cnt1 = 0,cnt2 = 0;
    cin >> p >> q;
    cout << p << '/' << q << " = ";
    vector<ll> ans;
    while(p%q){
        ans.push_back(p/q);
        p = p % q;
        swap(p,q);
        cnt1++;cnt2++;
    }ans.push_back(p/q);
    if(cnt1 == 0){
        cout << p / q;
        return;
    }cnt1--;
    for(auto x:ans){
        cout << x;
        if(cnt1 >= 0)cout << "+1/";
        if(cnt1 > 0)cout << '{';
        cnt1--;
    }while(cnt2-- > 1)cout << '}';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        murname();
        cout << '\n';
    }

    return 0;
}
