/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-03 13:55:22
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-03 13:58:40
 */
#include <iostream>

using namespace std;

int a[10] = {0};

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = n; i <= m; ++i) {
        int k = i;
        while (k > 0) {
            a[k % 10]++;
            k /= 10;
        }
    }

    for (int i = 0; i < 10; ++i) {
        cout << a[i];
        if (i < 9) cout << ' ';
    }

    return 0;
}
