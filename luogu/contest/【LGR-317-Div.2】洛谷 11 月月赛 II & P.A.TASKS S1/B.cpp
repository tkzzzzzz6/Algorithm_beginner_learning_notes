#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>
#include <vector>

using namespace std;
using ll = long long;
using Node = pair<int, ll>;

void solve() {
    int n, s, t;
    cin >> n >> s >> t;
    vector<int> q(n), l(n), r(n);

    for (int i = 0; i < n; ++i) cin >> q[i];
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    priority_queue<Node, vector<Node>, greater<Node>> heap;
    ll used = 0;
    ll quality = 0;

    for (int i = 0; i < n; ++i) {
        used += r[i];
        quality += 1LL * r[i] * q[i];

        if (r[i] > l[i]) heap.push({q[i], r[i] - l[i]});

        ll deadline = s + 1LL * t * i;
        while (used - deadline > 0 && !heap.empty()) {
            auto [q, cnt] = heap.top();
            heap.pop();

            ll cut = min(used - deadline, cnt);
            used -= cut;
            quality -= cut * q;
            if (cut < cnt) {
                heap.push({q, cnt - cut});
            }
        }
        if (used - deadline > 0) {
            cout << "Bansakutsukita!" << '\n';
            return;
        }
    }
    cout << quality << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
