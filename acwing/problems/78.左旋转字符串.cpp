/*
 * @acwing app=acwing.cn id=74 lang=C++
 *
 * 78. 左旋转字符串
 */

// @acwing code start

class Solution {
   public:
    string leftRotateString(string str, int n) {
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + str.size() - n); // 左开右闭区间,下一行翻转的开头是这一行的结尾
        reverse(str.begin() + str.size() - n, str.end()); 

        return str;
    }
};
// @acwing code end
