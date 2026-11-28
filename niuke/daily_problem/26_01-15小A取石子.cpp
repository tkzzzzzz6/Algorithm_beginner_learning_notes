#include <bits/stdc++.h>
using namespace std;
void solve() {
    // nim博弈
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &v : arr)
        cin >> v;
    int xorsum = 0;
    for (auto &v : arr) {
        xorsum ^= v;
    }
    if (xorsum == 0) {
        int maxv = *max_element(arr.begin(), arr.end());
        if (maxv < k || k == 0) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
    } else {
        cout << "YES\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
