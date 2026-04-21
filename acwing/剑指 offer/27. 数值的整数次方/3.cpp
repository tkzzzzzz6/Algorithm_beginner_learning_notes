/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 10:53:39
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 11:13:37
 */
/*
* @acwing app=acwing.cn id=26 lang=C++
*
* 27. 数值的整数次方
*/

// @acwing code start

class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0)return 0.0;
        if(base == 1 || exponent == 0)
            return 1.0;

        long long exp = exponent;
        double res = 1.0;
        if(exp < 0)exp = -exp;

        while(exp){
            if(exp&1)res*=base;
            base*=base;
            exp>>=1;
        }

        return exponent < 0 ? 1/res : res;
    }
};
// @acwing code end
