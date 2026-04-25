
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        if (i < m) {
            cout << "OK\n";
        }
        else {
        cout << "Too Many Requests\n";
        }
    }

    return 0;
}

