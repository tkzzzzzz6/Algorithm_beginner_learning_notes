/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=30204
 *
 * [1047] 删除字符串中的所有相邻重复项
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
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto c:s){
            if(st.empty() || c != st.top())st.push(c);
            else st.pop();
        }

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

 */
