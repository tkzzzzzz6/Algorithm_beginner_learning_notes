
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a < b)cout << '<';
    else if (a == b)cout << '=';
    else cout << '>';

    return 0;
}