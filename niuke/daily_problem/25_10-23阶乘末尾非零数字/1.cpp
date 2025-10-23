//上面的这段代码无法通过全部示例, 当n = 21的时候ans出现溢出, 需要考虑其他的求解方法
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