#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (auto x : s) {
            if (x == '.') ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}
