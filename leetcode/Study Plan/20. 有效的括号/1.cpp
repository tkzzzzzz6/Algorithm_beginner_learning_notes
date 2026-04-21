// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-15 23:44:18
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-15 23:56:29
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        int n = s.size();
        if(n % 2 != 0)return false;
        stack<char> st;
        for(int i = 0;i<n;++i){
            if(s[i] == '[')st.push(']');
            else if(s[i] == '(')st.push(')');
            else if(s[i] == '{')st.push('}');
            else if(st.empty() || s[i] != st.top())return false;
            else st.pop();
        }
        return st.empty();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */
