/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-11 00:11:27
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-11 00:11:34
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode* > visited;
        while(head != nullptr){
            if(visited.count(head)){
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return NULL;
    }
};
