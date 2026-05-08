/*
 * @acwing app=acwing.cn id=73 lang=C++
 *
 * 77. 翻转单词顺序
 */

// @acwing code start

class Solution {
   public:
    string reverseWords(string s) {
        // 1. 先翻转整个句子
        reverse(s.begin(), s.end());

        // 2. 翻转每个单词
        for (int i = 0; i < s.size(); ++i) {
            int j = i;
            while (j < s.size() && s[j] != ' ')
                ++j;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }

        return s;
    }
};
// @acwing code end
