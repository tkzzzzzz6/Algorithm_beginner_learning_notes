//多项式加法

struct PolyNode {
    int coef;
    int expon;
    struct PolyNode *link;
};//定义一个链表用于存储系数指数

typedef struct PolyNode *Polynomial;

Polynomial P1, P2;

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
    Polynomial front, rear, temp; // 定义指针用于创建结果多项式
    int sum; // 用于存储系数之和
    rear = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建头节点
    front = rear; // front指向头节点
    // 由front记录结果多项式链表头结点
    while(P1 && P2) // 当两个多项式都有非零项待处理时
    {
        switch(Compare(P1->expon, P2->expon)) // 比较两个多项式当前项的指数
        {
            case 1: // P1指数大
                Attach(P1->coef, P1->expon, &rear); // 将P1当前项添加到结果多项式
                P1 = P1->link; // P1指向下一项
                break;
            case -1: // P2指数大
                Attach(P2->coef, P2->expon, &rear); // 将P2当前项添加到结果多项式
                P2 = P2->link; // P2指向下一项
                break;
            case 0: // 指数相等
                sum = P1->coef + P2->coef; // 计算系数之和
                if(sum) Attach(sum, P1->expon, &rear); // 如果和不为0，将新项添加到结果多项式
                P1 = P1->link; // P1指向下一项
                P2 = P2->link; // P2指向下一项
                break;
        }
    }
    // 将未处理完的另一个多项式的所有节点依次复制到结果多项式中去
    for(; P1; P1 = P1->link) Attach(P1->coef, P1->expon, &rear); // 处理P1中剩余的项
    for(; P2; P2 = P2->link) Attach(P2->coef, P2->expon, &rear); // 处理P2中剩余的项
    rear->link = NULL; // 设置结果多项式的末尾
    temp = front; // 保存头节点
    front = front->link; // 令front指向结果多项式第一个非零项
    free(temp); // 释放临时空表头结点
    return front; // 返回结果多项式
}