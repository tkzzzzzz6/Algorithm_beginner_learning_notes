#define MAX(a,b) ((a)>(b)?(a):(b))

typedef struct{
    int length;
    struct ListNode *head;
} MyLinkedList;

struct ListNode *ListNodeCreat(int val){
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

MyLinkedList *myLinkedListCreate(){
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    obj->head = ListNodeCreat(0);
    obj->length = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList *obj,int index){
    if(index < 0 || index >= obj->length){
        return -1;
    }
    struct ListNode *cur = obj->head;
    for (int i = 0;i<=index;i++){
        cur = cur->next;
    }
    return cur->val;
}

void myLinkedListAddAtIndex(MyLinkedList *obj,int index,int val){
    if(index > obj->length){
        return;
    }
    index = MAX(0,index);
    obj->length++;
    struct ListNode *pred = obj->head;
    for (int i = 0;i<index;i++){
        pred = pred->next;
    }
    struct ListNode *to_add = ListNodeCreat(val);
    to_add->next = pred->next;
    pred->next = to_add;
}

void myLinkedListAddAtHead(MyLinkedList *obj,int val){
    myLinkedListAddAtIndex(obj,0,val);
}

void myLinkedListAddAtTail(MyLinkedList *obj,int val){
    myLinkedListAddAtIndex(obj,obj->length,val);
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj,int index){
    if(index < 0 || index >= obj->length){
        return;
    }
    obj->length--;
    struct ListNode *pred = obj->head;
    for (int i = 0;i<index;i++){
        pred = pred->next;
    }
    struct ListNode *p = pred->next;
    pred->next = pred->next->next;
    free(p);
}

void myLinkedListFree(MyLinkedList *obj){
    struct ListNode *cur = NULL,*tmp = NULL;
    for (struct ListNode *p = obj->head;p!=NULL;p = tmp){
        tmp = p->next;
        free(p);
    }
}
