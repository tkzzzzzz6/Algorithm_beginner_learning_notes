/*
 * @acwing app=acwing.cn id=51 lang=C++
 *
 * 56. 从1到n整数中1出现的次数
 */

// @acwing code start

class Solution {
   public:
    int numberOf1Between1AndN_Solution(int n) {
        if (!n)
            return 0;
        int res = 0;
        vector<int> digits;
        while (n)
            digits.push_back(n % 10), n /= 10;

        for (int i = 0; i < digits.size(); ++i) {
            int left = 0, right = 0, t = 1;
            for (int j = digits.size() - 1; j > i; --j)
                left = left * 10 + digits[j];
            for (int j = i - 1; j >= 0; --j)
                right = right * 10 + digits[j], t *= 10;
            res += left * t;
            if (digits[i] == 0)
                ;
            else if (digits[i] == 1) {
                res += right + 1;
            } else if (digits[i] > 1) {
                res += t;
            }
        }

        return res;
    }
};
// @acwing code end
