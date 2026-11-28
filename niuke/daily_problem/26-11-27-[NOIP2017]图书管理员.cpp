/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-27 17:45:11
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-27 21:33:02
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    int n, q;
    cin >> n >> q;

    vector<ll> book_ids(n);
    for (auto &book : book_ids) cin >> book;
    sort(book_ids.begin(), book_ids.end());

    while (q--) {
        int len;
        cin >> len;
        ll user_token;
        cin >> user_token;

        int mod = 1, ans = -1;
        while (len--) mod *= 10;
        for (const ll b : book_ids) {
            if (b % mod == user_token) {
                ans = b;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
