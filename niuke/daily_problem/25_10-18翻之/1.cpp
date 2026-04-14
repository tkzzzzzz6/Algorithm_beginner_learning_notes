#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 洢ַ
vector<vector<char>> martix;

// ϣֵַǸгֵĴ
unordered_map<string, int> mp;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m;
    cin >> n >> m;

    // ʼ n  m еַ
    martix.resize(n, vector<char>(m));

    // ÿַ
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> martix[i][j];
        }
    }

    // ÿһУÿеַƴӳַ
    for (int j = 0; j < m; ++j) {
        string s = "";
        // ϵƴӵ j еַ
        for (int i = 0; i < n; ++i) {
            s += martix[i][j];
        }
        // ͳƸֵַĴ
        mp[s]++;
    }

    // ҳִУظ
    int max_cnt = 0;
    for (auto& [str, cnt] : mp) {
        max_cnt = max(max_cnt, cnt);
    }

    // жȫͬ
    cout << max_cnt << '\n';

    return 0;
}


