
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int collatz_func(int n) {
    if (n & 1)return 3 * n + 1;
    else return n / 2;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    cout << collatz_func(n) << '\n';

    return 0;
}