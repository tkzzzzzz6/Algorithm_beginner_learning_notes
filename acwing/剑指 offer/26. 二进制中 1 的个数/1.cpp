/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 09:51:07
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 09:51:09
 */
/*
* @acwing app=acwing.cn id=25 lang=C++
*
* 26. 二进制中1的个数
*/

// @acwing code start

class Solution {
public:
    int NumberOf1(int n) {
        unsigned int us_n = n;
        int s = 0;
        
        while(us_n)s += us_n & 1,us_n >>= 1;
        
        return s;
    }
};
// @acwing code end
