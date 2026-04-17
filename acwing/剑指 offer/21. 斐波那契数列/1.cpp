/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-17 13:21:31
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-17 13:37:21
 */
/*
* @acwing app=acwing.cn id=19 lang=C++
*
* 21. 斐波那契数列
*/

// @acwing code start

class Solution {
public:
int Fibonacci(int n) {
        int res[n+1];
        res[0] = 0,res[1] = 1;
        for(int i = 2;i<=n;++i){
            res[i] = res[i-1]+res[i-2];
        }
        return res[n];
    }
};
// @acwing code end
