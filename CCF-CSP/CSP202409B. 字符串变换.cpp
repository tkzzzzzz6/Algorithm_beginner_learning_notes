/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-30 10:49:28
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-30 19:11:49
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;
    getline(cin, line);
    string s = line.substr(1, line.size() - 2);

    int n;
    cin >> n;
    cin.ignore();

    unordered_map<char, char> f;
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        f[line[1]] = line[2];
    }

    auto get_f = [&](char ch) -> char {
        auto it = f.find(ch);
        return it != f.end() ? it->second : ch;
    };

    unordered_set<char> visited;
    unordered_map<char, vector<char>> char_to_cycle;
    unordered_map<char, int> char_to_idx;

    for (char ch : s) {
        if (visited.count(ch)) continue;

        vector<char> path;
        char cur = ch;
        while (!visited.count(cur)) {
            visited.insert(cur);
            path.push_back(cur);
            cur = get_f(cur);
        }

        auto it = find(path.begin(), path.end(), cur);
        vector<char> cycle(it, path.end());

        for (int i = 0; i < (int)cycle.size(); ++i) {
            char_to_cycle[cycle[i]] = cycle;
            char_to_idx[cycle[i]] = i;
        }
    }

    int m;
    cin >> m;
    vector<long long> ks(m);
    for (int i = 0; i < m; ++i) cin >> ks[i];

    for (long long k : ks) {
        string res;
        res.reserve(s.size());
        for (auto ch : s) {
            const auto &cyc = char_to_cycle[ch];
            int idx = char_to_idx[ch];
            int new_idx = (idx + k) % (int)cyc.size();
            res.push_back(cyc[new_idx]);
        }
        cout << '#' << res << "#\n";
    }

    return 0;
}
