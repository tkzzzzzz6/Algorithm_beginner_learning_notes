/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-27 14:28:21
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-27 14:41:54
 */
#include <iostream>

using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    int res = 0;
    int size = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        size += a;
        if (size < k)
            continue;
        res++;
        size = 0;
    }

    if (size > 0) res++;

    cout << res << endl;
    return 0;
}
