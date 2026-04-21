/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-18 22:38:12
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-18 22:38:17
 */
/*
* @acwing app=acwing.cn id=24 lang=C++
*
* 25. 剪绳子
*/

// @acwing code start

class Solution {
public:
    int maxProductAfterCutting(int length) {
        if(length <= 3)return 1 * (length-1);

        int res = 1;

        if(length % 3 == 1)length-=4,res = 4;
        else if(length % 3 == 2)length-=2,res =2;
        
        while(length)res*=3,length-=3;
        return res;
    }
};
// @acwing code end

