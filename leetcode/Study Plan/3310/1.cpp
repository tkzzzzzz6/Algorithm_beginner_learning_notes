/*
 * @lc app=leetcode.cn id=3110 lang=cpp
 *
 * [3110] 字符串的分数
 */

#include <string>
#include <iostream>
#include <math.h>

// @lc code=start
class Solution
{
public:
    int scoreOfString(std::string s)
    {
        int ans = 0;
        for (int i = 0, j = 1; j < s.size(); ++i, ++j)
        {
            int n = s[i] - '0';
            int m = s[j] - '0';
            ans += abs(n - m);
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // std::cout << int('h' - '0') << std::endl;
    std::string s = "hello";
    std::cout << solution.scoreOfString(s) << std::endl;
    return 0;
}
