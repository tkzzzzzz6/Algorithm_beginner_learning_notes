/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-27 14:52:01
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-27 16:10:24
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using PII = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<PII> pst(n);
    set<PII> s;
    int dx4[4] = {0, 0, -1, 1}, dy4[4] = {-1, 1, 0, 0};
    int dx8[4] = {-1, 1, -1, 1}, dy8[4] = {-1, -1, 1, 1};
    int ans[5] = {0};
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        pst[i] = {x, y};
        s.insert(pst[i]);
    }

    for (auto &[x, y] : pst) {
        bool ok = true;
        for (int i = 0; i < 4; ++i) {
            if (!s.count({x + dx4[i], y + dy4[i]})) {
                ok = false;
                break;
            }
        }

        if (!ok) continue;

        int score = 0;
        for (int i = 0; i < 4; ++i) {
            if (s.count({x + dx8[i], y + dy8[i]})) ++score;
        }
        ans[score]++;
    }

    for (int i = 0; i < 5; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
