#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        string x;
        cin >> x;

        vector<pair<int,int>> ops;
        for (int i = 0; i < n; ) {
            if (x[i] == '1') {
                int j = i;
                while (j < n && x[j] == '1') j++;
                ops.push_back({i + 1, j}); // 转为 1-based
                i = j;
            } else i++;
        }

        if ((int)ops.size() > 5) {
            cout << -1 << "\n";
        } else {
            cout << ops.size() << "\n";
            for (auto [l, r] : ops)
                cout << l << " " << r << "\n";
        }
    }
    return 0;
}
