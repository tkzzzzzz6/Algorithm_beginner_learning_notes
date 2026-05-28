/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-27 15:46:17
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-27 19:12:17
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Tree {
    int x, y;
    bool operator<(const Tree &other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

int main() {
    int n, L, S;
    cin >> n >> L >> S;

    // 1.存储所有树的位置
    vector<Tree> Trees(n);
    set<Tree> st;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        Trees[i] = {x, y};
        st.insert({x, y});
    }

    // 2.读入藏宝图,注意这里我们的 bMap 从左下角开始
    vector<vector<int>> bMap(S + 1, vector<int>(S + 1));
    for (int k = 0; k <= S; ++k) {
        for (int j = 0; j <= S; ++j) {
            cin >> bMap[S - k][j];
        }
    }

    // 3.以每个树为起点遍历
    int ans = 0;
    for (auto &p : Trees) {
        int x = p.x, y = p.y;

        if (x + S > L || y + S > L) continue;

        bool ok = true;
        for (int i = 0; i <= S && ok; ++i) {
            for (int j = 0; j <= S; ++j) {
                bool hasTree = st.count((Tree{x + i, y + j}));

                if (bMap[i][j] == 1 && !hasTree) {
                    ok = false;
                    break;
                }
                if (bMap[i][j] == 0 && hasTree) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) ++ans;
    }

    cout << ans << '\n';

    return 0;
}
