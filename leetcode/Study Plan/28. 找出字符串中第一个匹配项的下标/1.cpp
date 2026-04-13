/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-14 01:08:25
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-14 01:21:50
 */
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30204
 *
 * [28] 找出字符串中第一个匹配项的下标
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
    int strStr(string haystack, string needle) {
        int m = haystack.size(),n = needle.size();
        if(n == 0)return -1;
        string s = needle + '#' + haystack;
        vector<int> pi(s.size());
        for(int i = 1;i<s.size();++i){
            int len = pi[i - 1];
            while(len && s[i] != s[len]){
                len = pi[len-1];
            }
            if(s[i] == s[len]){
                pi[i] = len + 1;
                if(pi[i] == n)return i-2*n;
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */
