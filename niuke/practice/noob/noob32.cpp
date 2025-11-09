
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (i & 1)sum += i;
        else sum -= i;
    }

    cout << sum << '\n';

    return 0;
}