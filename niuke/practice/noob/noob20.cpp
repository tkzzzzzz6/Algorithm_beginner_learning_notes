
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get_sum(int n) {
    if (n == 1)return 1;
    else return ll(n) * (n + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    cout << get_sum(n) << '\n';

    return 0;
}