/*
* @acwing app=acwing.cn id=32 lang=C++
*
* 33. 链表中倒数第k个节点
*/

// @acwing code start

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findKthToTail(ListNode* head, int k) {
        int n = 0;
        for(auto cur = head;cur != nullptr;cur = cur->next){
            ++n;
        }

        if(k > n)return nullptr;

        auto p = head;
        for(int i = 0;i<n-k;++i){
            p = p->next;
        }

        return p;
    }
};
// @acwing code end
