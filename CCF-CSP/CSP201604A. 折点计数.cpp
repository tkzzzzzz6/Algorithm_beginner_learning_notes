/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-28 22:43:04
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-28 22:45:52
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    int res = 0;

    for (int i = 1; i < n - 1; ++i) {
        int sub1 = a[i] - a[i - 1];
        int sub2 = a[i + 1] - a[i];

        if (sub1 * sub2 < 0) ++res;
    }

    cout << res << '\n';

    return 0;
}
