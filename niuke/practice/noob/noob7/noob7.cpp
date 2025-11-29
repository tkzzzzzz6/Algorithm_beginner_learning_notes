
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(3);

    int d, c;
    cin >> c >> d;
    cout << (d / double(c) * 100) << '%';
    cout.unsetf(ios::fixed);
    cout.flush();
    return 0;
}