/*
 * @acwing app=acwing.cn id=55 lang=C++
 *
 * 59. 把数字翻译成字符串
 */

// @acwing code start

class Solution {
   public:
    int getTranslationCount(string s) {
        int n = s.size();
        vector<int> f(n + 1, 0);
        f[0] = 1, f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            f[i] += f[i - 1];
            int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (10 <= t && t <= 25)
                f[i] += f[i - 2];
        }

        return f[n];
    }
};
// @acwing code end
