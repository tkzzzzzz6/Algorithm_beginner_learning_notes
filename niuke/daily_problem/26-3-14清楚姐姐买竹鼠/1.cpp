/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-14 23:29:48
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-15 00:10:37
 */
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ll a,b,x;
    cin >> a >> b >> x;
    ll cost1 = a*x;
    ll cost2 = ((x+2)/3)*b;
    ll cost3 = (x/3)*b + (x%3)*a;

    cout << min({cost1,cost2,cost3}) << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
