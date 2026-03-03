#include <iostream>
#include <string>
#include <vector>

using namespace std;
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
        for (char c : s) {
            switch (c) {
            case '[':
            case '(':
            case '{':
                st.push_back(c);
                break;
            case ']':
                if (!st.empty() && st.back() == '[') {
                    st.pop_back();
                } else {
                    return false;
                }
                break;
            case ')':
                if (!st.empty() && st.back() == '(') {
                    st.pop_back();
                } else {
                    return false;
                }
                break;
            case '}':
                if (!st.empty() && st.back() == '{') {
                    st.pop_back();
                } else {
                    return false;
                }
                break;
            }
        }
        return st.empty() ? true : false;
    }
};
