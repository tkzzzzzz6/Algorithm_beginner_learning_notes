/*
 * @Author: tkzzzzzz6
 * @Date: 2026-08-14 18:01:13
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-08-14 18:40:11
 */
/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 * @lcpr version=30204
 *
 * [3090] 每个字符最多出现两次的最长子字符串
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
    int maximumLengthSubstring(string s) {
        int ans = 0, left = 0, cnt[26]{};

        for (int i = 0; i < s.length(); ++i) {
            int b = s[i] - 'a';
            cnt[b]++;

            while (cnt[b] > 2) {
                cnt[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "bcbbbcba"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

 */
