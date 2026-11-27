/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-25 14:26:53
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-25 14:47:03
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        string s, t;
        cin >> s >> t;

        vector<int> used(max(0, n - 1), 0);
        string cur = s;

        for (int i = 0; i < n; ++i) {
            if (t[i] == cur[i]) continue;

            int j = i + 1;
            while (j < n && t[i] != cur[j]) ++j;

            for (int k = j; k > i; --k) {
                swap(cur[k], cur[k - 1]);
                used[k - 1] = 1;
            }
        }

        ans = count(used.begin(), used.end(), 1);
        cout << ans << endl;
    }
    return 0;
}
