
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int s, v;
    s = 2 * (a * b + c * b + a * c);
    v = a * b * c;
    cout << s << '\n';
    cout << v << '\n';

    return 0;
}