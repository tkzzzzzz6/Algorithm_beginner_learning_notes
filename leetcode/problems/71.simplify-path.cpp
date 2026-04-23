/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-20 15:13:56
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-21 23:00:00
 */
/*
 * @lc app=leetcode.cn id=71 lang=cpp
 * @lcpr version=30204
 *
 * [71] 简化路径
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
#include <tuple>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;

        stringstream ss(path);
        string s;

        while(getline(ss,s,'/')){
            if(s == "." || s.empty() )
                continue;
            if(s == ".."){
                if(!st.empty())st.pop_back();
            }
            else{
                st.push_back(s);
            }
        }

        string res;
        for(auto &x:st){
            res += "/";
            res += x;
        }

        return res.empty() ? "/": res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

// @lcpr case=start
// "/home/user/Documents/../Pictures"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/.../a/../b/c/../d/./"\n
// @lcpr case=end

 */
