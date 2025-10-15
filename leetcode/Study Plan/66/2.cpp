/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <vector>
#include <iostream>

// @lc code=start
class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] != 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        // 这里有一个逻辑错误：当所有位都是9时（如[9,9,9]），
        // 我们需要在最前面插入1，而不是修改digits[0]并添加0到末尾
        // 修正方法是：创建一个新的vector，第一位为1，后面跟n个0
        std::vector<int> result(n + 1, 0);
        result[0] = 1;
        return result;
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector<int> digits = {9, 9, 9};
    auto res = s.plusOne(digits);
    for (auto x : res)
        std::cout << x << " ";
    return 0;
}
