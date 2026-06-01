/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-29 11:03:50
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-29 11:08:15
 */
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int r[1010] = {0};
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        r[a]++;
        cout << r[a] << ' ';
    }

    return 0;
}
