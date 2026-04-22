/*
#include <vector>
* @acwing app=acwing.cn id=40 lang=C++
*
* 42. 栈的压入、弹出序列
*/

// @acwing code start

class Solution {
public:
    stack<int> st;
    bool isPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size())return false;

        int j = 0;
        for(int x:pushV){
            st.push(x);
            while(!st.empty() && j < popV.size() && st.top() == popV[j]){
                st.pop();
                ++j;
            }
        }

        return j == popV.size();
    }
};
// @acwing code end
