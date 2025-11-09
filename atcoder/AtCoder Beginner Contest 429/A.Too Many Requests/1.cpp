#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cout << (i <= m ? "OK" : "Too Many Requests") << "\n";
    }
    return 0;
}