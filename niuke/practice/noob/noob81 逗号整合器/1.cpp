/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-18 15:32:42
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-18 15:40:24
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 整理出一个将序列中的数字以逗号隔开从而得到的字符串
     * @param a int整型vector 需要整理的序列 a
     * @return string字符串
     */
    string commaTransformer(vector<int> &a) {
        // write code here
        int n = a.size();
        if(n == 0){
            return "";
        }
        string s = "";
        for(int i =0;i<n-1;++i){
            s += to_string(a[i]);
            s += ',';
        }
        s += to_string(a[n-1]);
        return s;
    }
};
