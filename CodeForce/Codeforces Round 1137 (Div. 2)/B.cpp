#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int len = n - k + 1, ans = 0, same = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && a[i] == a[i - 1])
                ++same;
            else
                same = 1;
            if (same >= len) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
