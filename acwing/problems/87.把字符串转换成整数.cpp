/*
 * @acwing app=acwing.cn id=83 lang=C++
 *
 * 87. 把字符串转换成整数
 */

// @acwing code start

class Solution {
   public:
    int strToInt(string str) {
        int minus = 1;
        int x = 0;
        long long res = 0;

        // 去除开头空格
        while (x < str.size() && str[x] == ' ')
            ++x;

        // 判断正负
        if (x < str.size()) {
            if (str[x] == '-')
                minus = -1, ++x;
            if (str[x] == '+')
                ++x;
        }

        // 字符转化为整数,注意提前终止
        while (x < str.size() && '0' <= str[x] && str[x] <= '9') {
            res = res * 10 + (str[x] - '0');
            if (res > INT_MAX)
                break;
            ++x;
        }

        res *= minus;
        if (res > INT_MAX)
            return INT_MAX;
        if (res < INT_MIN)
            return INT_MIN;

        return res;
    }
};
// @acwing code end
