/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-02 21:29:02
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-02 21:54:42
 */
#include <iostream>

using namespace std;

int a[11] = {0};
int cnt[11] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 7; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) {
        int d = 0;
        for (int j = 0; j < 7; ++j) {
            int x;
            cin >> x;
            for (int k = 0; k < 7; ++k) {
                if (a[k] == x) {
                    ++d;
                    break;
                }
            }
        }
        cnt[d]++;
    }

    for (int i = 7; i >= 1; --i) {
        cout << cnt[i];
        if (i > 1) cout << ' ';
    }

    return 0;
}
