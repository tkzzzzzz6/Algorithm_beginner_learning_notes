
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime(int n) {
    if (n <= 1)return false;
    int m = int(sqrt(n) + 0.5);
    for (int i = 2; i <= m; ++i) {
        if (n % i == 0)return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (is_prime(n))cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}