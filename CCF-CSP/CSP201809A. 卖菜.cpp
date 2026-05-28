/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-28 21:12:50
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-28 21:23:49
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

    cout << (a[0] + a[1]) / 2 << ' ';

    for (int i = 1; i < n - 1; ++i)
        cout << (a[i - 1] + a[i + 1] + a[i]) / 3 << ' ';

    cout << (a[n - 2] + a[n - 1]) / 2;

    return 0;
}
