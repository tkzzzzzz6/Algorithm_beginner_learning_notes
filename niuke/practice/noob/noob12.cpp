
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    do {
        cout << n % 10;
    } while (n /= 10);

    return 0;
}