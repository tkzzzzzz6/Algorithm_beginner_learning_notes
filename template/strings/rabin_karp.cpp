/*
 * Rabin-Karp算法
 * 用途：字符串匹配（支持多模式匹配）
 * 时间复杂度：平均 O(n + m)，最坏 O(nm)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long BASE = 31;

class RabinKarp {
private:
    long long base, mod;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

public:
    RabinKarp(long long b = BASE, long long m = MOD) : base(b), mod(m) {}

    // 计算字符串的哈希值
    long long hash(string s) {
        long long h = 0;
        for (char c : s) {
            h = (h * base + c) % mod;
        }
        return h;
    }

    // 查找所有匹配位置
    vector<int> search(string text, string pattern) {
        int n = text.length(), m = pattern.length();
        if (m > n) return {};

        vector<int> result;
        long long patternHash = hash(pattern);
        long long textHash = hash(text.substr(0, m));
        long long highestPow = power(base, m - 1);

        if (textHash == patternHash && text.substr(0, m) == pattern) {
            result.push_back(0);
        }

        for (int i = 1; i <= n - m; i++) {
            // 滚动哈希
            textHash = (textHash - text[i-1] * highestPow % mod + mod) % mod;
            textHash = (textHash * base + text[i + m - 1]) % mod;

            if (textHash == patternHash &&
                text.substr(i, m) == pattern) {
                result.push_back(i);
            }
        }

        return result;
    }

    // 多模式匹配
    map<int, vector<string>> multiSearch(string text,
                                        vector<string>& patterns) {
        map<long long, vector<string>> hashToPattern;
        for (const string& p : patterns) {
            hashToPattern[hash(p)].push_back(p);
        }

        map<int, vector<string>> result;
        int n = text.length();

        for (auto& [h, pList] : hashToPattern) {
            int m = pList[0].length();
            if (m > n) continue;

            long long textHash = hash(text.substr(0, m));
            long long highestPow = power(base, m - 1);

            if (textHash == h) {
                for (const string& p : pList) {
                    if (text.substr(0, m) == p) {
                        result[0].push_back(p);
                    }
                }
            }

            for (int i = 1; i <= n - m; i++) {
                textHash = (textHash - text[i-1] * highestPow % mod + mod) % mod;
                textHash = (textHash * base + text[i + m - 1]) % mod;

                if (textHash == h) {
                    for (const string& p : pList) {
                        if (text.substr(i, m) == p) {
                            result[i].push_back(p);
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    RabinKarp rk;

    string text = "ABABDABACDABABCABAB";
    string pattern = "ABAB";

    vector<int> matches = rk.search(text, pattern);
    cout << "Pattern found at: ";
    for (int pos : matches) {
        cout << pos << " ";
    }
    cout << endl;

    // 多模式匹配
    vector<string> patterns = {"ABAB", "BAC", "CABC"};
    auto multiMatches = rk.multiSearch(text, patterns);

    cout << "\nMulti-pattern search:" << endl;
    for (auto& [pos, pList] : multiMatches) {
        cout << "Position " << pos << ": ";
        for (const string& p : pList) {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}
