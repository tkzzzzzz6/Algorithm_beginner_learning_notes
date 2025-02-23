 #ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED


#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;              //数据元素
    struct node *lchild;        //指向左孩子
    struct node *rchild;        //指向右孩子
} BTNode;
void CreateBTNode(BTNode *&b,char *str);        //由str串创建二叉链
BTNode *FindNode(BTNode *b,ElemType x);     //返回data域为x的节点指针
BTNode *LchildNode(BTNode *p);  //返回*p节点的左孩子节点指针
BTNode *RchildNode(BTNode *p);  //返回*p节点的右孩子节点指针
int BTNodeDepth(BTNode *b); //求二叉树b的深度
void DispBTNode(BTNode *b); //以括号表示法输出二叉树
void DestroyBTNode(BTNode *&b);  //销毁二叉树
void LevelOrder(BTNode *b);
void PreOrder(BTNode *b);
void InOrder(BTNode *b);
void PostOrder(BTNode *b);



#endif // BTREE_H_INCLUDED
