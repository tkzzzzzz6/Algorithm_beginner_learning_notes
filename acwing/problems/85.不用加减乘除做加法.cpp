/*
* @acwing app=acwing.cn id=81 lang=C++
*
* 85. 不用加减乘除做加法
*/

// @acwing code start

class Solution {
public:
    int add(int num1, int num2){
        while(num2 != 0){
            int sum = num1 ^ num2; //不带进位的加法
            int carry = (num1 & num2) << 1; //代进位的加法
            num1 = sum;
            num2 = carry;
        }

        return num1;
    }
};
// @acwing code end
