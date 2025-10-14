/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



typedef struct {
    struct ListNode *head;
    int length;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->head = head;
    obj->length = 0;
    for (struct ListNode *p = head;p!=NULL;p = p->next){
        obj->length++;
    }
    return obj;
}

int solutionGetRandom(Solution* obj) {
    int index = rand() % obj->length;
    struct ListNode *cur = obj->head;
    for (int i = 0;i<index;i++){
        cur = cur->next;
    }
    return cur->val;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/