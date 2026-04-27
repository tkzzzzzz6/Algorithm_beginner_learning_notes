/*
 * @acwing app=acwing.cn id=59 lang=C++
 *
 * 63. 字符串中第一个只出现一次的字符
 */

// @acwing code start

class Solution {
   public:
    char firstNotRepeatingChar(string s) {
        unordered_map<char, int> cnt;
        for (auto x : s) {
            cnt[x]++;
        }

        for (auto x : s) {
            if (cnt[x] == 1)
                return x;
        }

        return '#';
    }
};
// @acwing code end
