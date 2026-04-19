/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 10:53:39
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 10:53:40
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
        double res = 1;
        for(int i = 0;i<abs(exponent);++i){
            res*=base;
        }
        if(exponent<0)return 1/res;
        return res;
    }
};
// @acwing code end
