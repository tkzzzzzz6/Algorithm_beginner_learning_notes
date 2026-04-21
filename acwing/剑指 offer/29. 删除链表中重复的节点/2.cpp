/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 19:00:36
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 19:04:39
 */
/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=30204
 *
 * [82] 删除排序链表中的重复元素 II
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
            if(cur->next->val == cur->next->next->val){
                int val = cur->next->val;
                while(cur->next && val == cur->next->val)
                    cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */
