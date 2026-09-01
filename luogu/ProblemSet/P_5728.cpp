#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(4, 0));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][3] = a[i][0] + a[i][1] + a[i][2];
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (i != j && abs(a[i][0] - a[j][0]) <= 5 && abs(a[i][1] - a[j][1]) <= 5 && abs(a[i][2] - a[j][2]) <= 5 && abs(a[i][3] - a[j][3]) <= 10) ++res;
        }
    }

    cout << res << '\n';

    return 0;
}
