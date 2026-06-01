#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    while (k--) {
        double u, s, n;
        cin >> u >> s >> n;
        double m = (n - u) / s;

        int baseline = (int)round(m * 100);
        cout << (baseline / 10) + 1 << ' ' << (baseline % 10) + 1 << '\n';
    }
    return 0;
}
