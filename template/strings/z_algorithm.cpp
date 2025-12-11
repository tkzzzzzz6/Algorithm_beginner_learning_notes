/*
 * Z算法 (Z Algorithm)
 * 用途：字符串匹配、找出所有前缀与字符串的某个子串相等的位置
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 * Z[i]: 从位置i开始的后缀与整个字符串的最长公共前缀长度
 */

#include <bits/stdc++.h>
using namespace std;

// 计算Z数组
vector<int> zAlgorithm(string s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && s[r - l] == s[r]) {
                r++;
            }
            z[i] = r - l;
            r--;
        } else {
            int k = i - l;
            if (z[k] < r - i + 1) {
                z[i] = z[k];
            } else {
                l = i;
                while (r < n && s[r - l] == s[r]) {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }

    return z;
}

// 使用Z算法进行模式匹配
vector<int> zSearch(string text, string pattern) {
    string combined = pattern + "$" + text;
    vector<int> z = zAlgorithm(combined);
    int m = pattern.length();

    vector<int> result;
    for (int i = m + 1; i < combined.length(); i++) {
        if (z[i] == m) {
            result.push_back(i - m - 1);
        }
    }

    return result;
}

int main() {
    string s = "aabcaabxaaaz";
    vector<int> z = zAlgorithm(s);

    cout << "Z array: ";
    for (int val : z) {
        cout << val << " ";
    }
    cout << endl;

    string text = "ABABDABACDABABCABAB";
    string pattern = "ABAB";
    vector<int> matches = zSearch(text, pattern);

    cout << "\nPattern matches at: ";
    for (int pos : matches) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
