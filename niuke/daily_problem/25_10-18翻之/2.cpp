
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> matrix;
unordered_map<string, int> mp;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m;
    cin >> n >> m;

    matrix.resize(n);

    cin.ignore();
    for (int i = 0; i < n; ++i)cin >> matrix[i];

    for (int j = 0; j < m; ++j) {
        string s = "";
        for (int i = 0; i < n; ++i) {
            s += matrix[i][j];
        }
        mp[s]++;
    }

    int max_cnt = 0;
    for (auto& [str, cnt] : mp) {
        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt << '\n';



    return 0;
}