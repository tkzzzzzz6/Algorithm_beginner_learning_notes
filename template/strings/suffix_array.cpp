/*
 * 后缀数组 (Suffix Array)
 * 用途：字符串的所有后缀按字典序排序
 * 时间复杂度：O(n log n)
 * 空间复杂度：O(n)
 * 应用：最长公共前缀、最长重复子串、子串查找
 */

#include <bits/stdc++.h>
using namespace std;

class SuffixArray {
private:
    string s;
    int n;
    vector<int> sa, rank, lcp;

    void buildSuffixArray() {
        sa.resize(n);
        rank.resize(n);
        vector<int> tmpRank(n);

        // 初始化
        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = s[i];
        }

        // 倍增算法
        for (int k = 1; k < n; k *= 2) {
            auto cmp = [&](int i, int j) {
                if (rank[i] != rank[j]) return rank[i] < rank[j];
                int ri = (i + k < n) ? rank[i + k] : -1;
                int rj = (j + k < n) ? rank[j + k] : -1;
                return ri < rj;
            };

            sort(sa.begin(), sa.end(), cmp);

            tmpRank[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                tmpRank[sa[i]] = tmpRank[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
            }
            rank = tmpRank;
        }
    }

    void buildLCP() {
        lcp.resize(n - 1);
        int k = 0;

        for (int i = 0; i < n; i++) {
            if (rank[i] == n - 1) {
                k = 0;
                continue;
            }

            int j = sa[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
                k++;
            }

            lcp[rank[i]] = k;
            if (k > 0) k--;
        }
    }

public:
    SuffixArray(string str) : s(str), n(str.length()) {
        buildSuffixArray();
        buildLCP();
    }

    vector<int> getSuffixArray() { return sa; }
    vector<int> getLCP() { return lcp; }

    // 查找模式串
    pair<int, int> search(string pattern) {
        int m = pattern.length();
        int l = 0, r = n;

        // 找第一个大于等于pattern的后缀
        while (l < r) {
            int mid = (l + r) / 2;
            if (s.substr(sa[mid], min(m, n - sa[mid])) < pattern) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        int start = l;

        // 找第一个大于pattern的后缀
        r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (s.substr(sa[mid], min(m, n - sa[mid])) <= pattern) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        int end = l;
        return {start, end};
    }

    // 最长重复子串
    string longestRepeatedSubstring() {
        int maxLen = 0, pos = 0;

        for (int i = 0; i < n - 1; i++) {
            if (lcp[i] > maxLen) {
                maxLen = lcp[i];
                pos = sa[i];
            }
        }

        return s.substr(pos, maxLen);
    }

    // 打印后缀数组
    void print() {
        cout << "Suffix Array:" << endl;
        for (int i = 0; i < n; i++) {
            cout << sa[i] << ": " << s.substr(sa[i]) << endl;
        }

        cout << "\nLCP Array: ";
        for (int i = 0; i < lcp.size(); i++) {
            cout << lcp[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    string s = "banana";
    SuffixArray sa(s);

    sa.print();

    // 搜索模式
    string pattern = "ana";
    auto [start, end] = sa.search(pattern);
    cout << "\nPattern '" << pattern << "' found " << (end - start)
         << " times" << endl;

    // 最长重复子串
    cout << "Longest repeated substring: "
         << sa.longestRepeatedSubstring() << endl;

    return 0;
}
