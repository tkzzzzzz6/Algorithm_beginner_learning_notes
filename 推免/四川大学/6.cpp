#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);

    for (auto& x : a) {
        cin >> x;
    }

    if (n < 2) {
        cout << "0\n";
        return 0;
    }

    int min_val = a[0], ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, a[i] - min_val);
        min_val = min(a[i], min_val);
    }

    cout << ans << '\n';
    return 0;
}
