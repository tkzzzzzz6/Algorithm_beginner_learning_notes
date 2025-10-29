
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    //cout << fixed << setprecision(3);

    int a;
    cin >> a;
    if (a > 0) {
        cout << a / 10 % 10;
    }
    else {
        cout << -a / 10 % 10;
    }
    cout.flush();
    return 0;
}