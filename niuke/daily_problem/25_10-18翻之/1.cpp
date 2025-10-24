#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 存储输入的字符矩阵
vector<vector<char>> martix;

// 哈希表：键是列字符串，值是该列出现的次数
unordered_map<string, int> mp;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 初始化 n 行 m 列的字符矩阵
    martix.resize(n, vector<char>(m));

    // 读入矩阵的每个字符
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> martix[i][j];
        }
    }

    // 遍历每一列，将每列的字符拼接成字符串
    for (int j = 0; j < m; ++j) {
        string s = "";
        // 从上到下拼接第 j 列的所有字符
        for (int i = 0; i < n; ++i) {
            s += martix[i][j];
        }
        // 统计该列字符串出现的次数
        mp[s]++;
    }

    // 找出出现次数最多的列（最大重复次数）
    int max_cnt = 0;
    for (auto& [str, cnt] : mp) {
        max_cnt = max(max_cnt, cnt);
    }

    // 输出最多有多少列是完全相同的
    cout << max_cnt << '\n';

    return 0;
}