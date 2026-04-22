
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    //8,16.32,64,128,216
    int n, k;
    cin >> n;

    if (n % 8 == 0) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < 100; ++i) {
        if (i < 10) {
            if ((n * 10 + i) % 8 == 0) {
                cout << i << '\n';
                return 0;
            }
            else continue;
        }
        else if (i >= 10) {
            if ((n * 100 + i) % 8 == 0) {
                cout << i << '\n';
                return 0;
            }
            else continue;
        }
    }

    return 0;
}