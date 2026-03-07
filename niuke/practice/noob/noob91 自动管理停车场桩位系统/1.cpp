/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-06 13:08:04
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-07 11:00:04
 */
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    stack<int> st;
    stack<int> min_st;
    void push(int value) {
        st.push(value);
        min_st.push(min_st.empty() ? value : ::min(min_st.top(), value));
    }
    void pop() {
        if (!st.empty()) {
            st.pop();
            min_st.pop();
        }
    }
    int top() {
        return st.top();
    }
    int min() {
        return min_st.top();
    }
};
