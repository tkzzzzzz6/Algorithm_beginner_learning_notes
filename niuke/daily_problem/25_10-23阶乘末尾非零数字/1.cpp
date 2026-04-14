#include <string>
#include <iostream>
//δ޷ͨȫʾ, n = 21ʱans, Ҫⷽ
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll factorial(ll n) {
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    ll n;
    cin >> n;
    ll ans = factorial(n);
    string str = to_string(ans);
    for (int i = str.size() - 1; i >= 0;--i) {
        if (str[i] != '0') {
            cout << str[i] << '\n';
            break;
        }
    }

    return 0;
}
