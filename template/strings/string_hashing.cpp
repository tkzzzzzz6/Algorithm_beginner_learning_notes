/*
 * 字符串哈希 (String Hashing)
 * 用途：快速比较字符串、子串匹配、回文判断
 * 时间复杂度：预处理 O(n)，查询 O(1)
 * 空间复杂度：O(n)
 */

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long BASE = 31;

class StringHash {
private:
    string s;
    vector<long long> hash, powBase;
    long long base, mod;

public:
    StringHash(string str, long long b = BASE, long long m = MOD)
        : s(str), base(b), mod(m) {
        int n = s.length();
        hash.resize(n + 1, 0);
        powBase.resize(n + 1);

        powBase[0] = 1;
        for (int i = 1; i <= n; i++) {
            powBase[i] = powBase[i-1] * base % mod;
            hash[i] = (hash[i-1] * base + s[i-1]) % mod;
        }
    }

    // 获取子串 [l, r) 的哈希值
    long long getHash(int l, int r) {
        long long h = (hash[r] - hash[l] * powBase[r-l] % mod + mod) % mod;
        return h;
    }

    // 比较两个子串是否相等
    bool equal(int l1, int r1, int l2, int r2) {
        return getHash(l1, r1) == getHash(l2, r2);
    }

    // 查找子串的所有出现位置
    vector<int> find(string pattern) {
        int m = pattern.length();
        StringHash patHash(pattern, base, mod);
        long long targetHash = patHash.getHash(0, m);

        vector<int> result;
        for (int i = 0; i + m <= s.length(); i++) {
            if (getHash(i, i + m) == targetHash) {
                result.push_back(i);
            }
        }

        return result;
    }
};

// 双哈希（降低碰撞概率）
class DoubleHash {
private:
    StringHash hash1, hash2;

public:
    DoubleHash(string s)
        : hash1(s, 31, 1e9 + 7),
          hash2(s, 37, 1e9 + 9) {}

    pair<long long, long long> getHash(int l, int r) {
        return {hash1.getHash(l, r), hash2.getHash(l, r)};
    }

    bool equal(int l1, int r1, int l2, int r2) {
        return hash1.equal(l1, r1, l2, r2) &&
               hash2.equal(l1, r1, l2, r2);
    }
};

// 应用：查找最长回文子串
string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return "";

    StringHash forward(s);
    string rev(s.rbegin(), s.rend());
    StringHash backward(rev);

    int maxLen = 1, start = 0;

    // 奇数长度回文
    for (int i = 0; i < n; i++) {
        int l = 0, r = min(i, n - 1 - i);
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (forward.getHash(i - mid, i) ==
                backward.getHash(n - 1 - i - mid, n - 1 - i)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        int len = 2 * l + 1;
        if (len > maxLen) {
            maxLen = len;
            start = i - l;
        }
    }

    // 偶数长度回文
    for (int i = 0; i < n - 1; i++) {
        int l = 0, r = min(i + 1, n - 1 - i);
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (forward.getHash(i - mid + 1, i + 1) ==
                backward.getHash(n - i - mid, n - i)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (l > 0) {
            int len = 2 * l;
            if (len > maxLen) {
                maxLen = len;
                start = i - l + 1;
            }
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s = "abacabad";
    StringHash sh(s);

    // 比较子串
    cout << "s[0:3] == s[4:7]: " << sh.equal(0, 3, 4, 7) << endl;

    // 查找子串
    string pattern = "aba";
    vector<int> positions = sh.find(pattern);
    cout << "Pattern '" << pattern << "' found at: ";
    for (int pos : positions) {
        cout << pos << " ";
    }
    cout << endl;

    // 最长回文子串
    string s2 = "babad";
    cout << "Longest palindrome in '" << s2 << "': "
         << longestPalindrome(s2) << endl;

    return 0;
}
