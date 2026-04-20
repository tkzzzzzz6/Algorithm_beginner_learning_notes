/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 18:52:47
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 18:59:06
 */
/*
 * @lc app=leetcode.cn id=83 lang=cpp
 * @lcpr version=30204
 *
 * [83] 删除排序链表中的重复元素
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto cur = dummy;
        while(cur->next && cur->next->next){
            int val = cur->next->val;
            while(cur->next->next && val == cur->next->next->val)cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */
