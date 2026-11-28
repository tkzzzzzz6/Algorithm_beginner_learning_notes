#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n & 1) {
            cout << "NO\n";
            continue;
        }
        bool same_adjunce = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                same_adjunce = true;
                break;
            }
        }
        cout << (same_adjunce ? "YES\n" : "NO\n");
    }
    return 0;
}
