/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 10:53:39
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 11:06:45
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
        if(exp < 0)exp = -exp;

        double res = qpow(base,exp);

        return exponent > 0 ? res : 1/res;
    }

    double qpow(double base,long long exp){
        if(exp == 0)return 1.0;

        double half = qpow(base,exp /2);
        if(exp%2==0)
            return half*half;
        else{
            return half*half*base;
        }
    }
};
// @acwing code end
