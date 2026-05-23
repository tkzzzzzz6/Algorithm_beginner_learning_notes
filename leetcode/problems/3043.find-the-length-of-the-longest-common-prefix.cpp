/*
 * @lc app=leetcode.cn id=3043 lang=cpp
 * @lcpr version=30204
 *
 * [3043] 最长公共前缀的长度
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
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        for(auto x:arr1){
            string s = to_string(x);
            for(int i = 1;i<=s.size();++i){ //枚举 s 的前缀,并压入哈希
                st.insert(s.substr(0,i));
            }
        }

        int ans = 0;
        for(auto x:arr2){
            string s = to_string(x);
            for(int i = 1;i<=s.size();++i){ //寻找 arr2 与 arr1 中共同有的前缀,并统计最大值
                if(!st.contains(s.substr(0,i)))break; 
                ans = max(ans,i);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,10,100]\n[1000]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[4,4,4]\n
// @lcpr case=end

 */
