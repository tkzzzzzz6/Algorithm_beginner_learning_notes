
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lastNonZeroDigit_factorial(ll n) {
    ll ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans *= i;
        while (ans % 10 == 0)ans /= 10;
        ans %= int(1e9); // 1e9是double需要强制转换
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    ll n;
    cin >> n;
    cout << lastNonZeroDigit_factorial(n) % 10 << '\n';

    return 0;
}