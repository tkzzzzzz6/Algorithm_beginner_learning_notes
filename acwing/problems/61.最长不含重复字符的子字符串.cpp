/*
 * @acwing app=acwing.cn id=57 lang=C++
 *
 * 61. 最长不含重复字符的子字符串
 */

// @acwing code start

class Solution {
   public:
    int longestSubstringWithoutDuplication(string s) {
        // cnt[c] 表示当前窗口 [i, j] 内字符 c 出现的次数
        unordered_map<char, int> cnt;
        int res = 0;

        for (int i = 0, j = 0; j < s.size(); ++j) {
            // 右指针 j 右移，把 s[j] 纳入窗口
            if (++cnt[s[j]] > 1) {
                // 出现重复字符时，左指针 i 右移，先跳过前面不重复的部分
                while (cnt[s[i]] == 1)
                    cnt[s[i++]]--;
                // 再跳过这个“重复字符”的前一次出现，窗口恢复为无重复
                cnt[s[i++]]--;
            }
            // 维护当前无重复窗口的最大长度
            res = max(res, j - i + 1);
        }

        return res;
    }
}; 
// @acwing code end
