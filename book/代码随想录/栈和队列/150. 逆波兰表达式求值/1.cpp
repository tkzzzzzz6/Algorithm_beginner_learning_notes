/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-18 23:35:27
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-18 23:50:14
 */
/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30204
 *
 * [150] 逆波兰表达式求值
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto c:tokens){
            if(c != "+" && c != "-" && c != "*" && c != "/"){
                st.push(stoi(c));
            }else{
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(c == "+"){
                    st.push(a+b);
                }else if(c == "-"){
                    st.push(a-b);
                }else if(c == "*"){
                    st.push(a*b);
                }else{
                    st.push(a/b);
                }
            }
        }
        return st.top();
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */
