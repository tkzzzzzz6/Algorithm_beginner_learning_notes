/*
 * KMP算法 (Knuth-Morris-Pratt)
 * 用途：字符串模式匹配
 * 时间复杂度：O(n + m)
 * 空间复杂度：O(m)
 */

#include <bits/stdc++.h>
using namespace std;

// 构建KMP的失配数组（前缀函数）
vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;

    for (int i = 1; i < m; i++) {
        while (len > 0 && pattern[i] != pattern[len]) {
            len = lps[len - 1];
        }
        if (pattern[i] == pattern[len]) {
            len++;
        }
        lps[i] = len;
    }

    return lps;
}

// KMP搜索（返回所有匹配位置）
vector<int> kmpSearch(string text, string pattern) {
    vector<int> result;
    if (pattern.empty()) return result;

    int n = text.length(), m = pattern.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}

// 查找第一个匹配
int kmpSearchFirst(string text, string pattern) {
    if (pattern.empty()) return -1;

    int n = text.length(), m = pattern.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            return i - j;
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return -1;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    vector<int> matches = kmpSearch(text, pattern);
    cout << "Pattern found at positions: ";
    for (int pos : matches) {
        cout << pos << " ";
    }
    cout << endl;

    int first = kmpSearchFirst(text, pattern);
    cout << "First match at: " << first << endl;

    return 0;
}
