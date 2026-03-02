/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-02 22:35:39
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-02 22:35:46
 */
class Solution {
   public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        vector<char> st;
        bool ok;
        for (char c : s) {
            switch (c) {
            case '[':
            case '(':
            case '{':
                st.push_back(c);
            case ']':
                if (!st.empty() && st)
            }
        }
    }
};
