#include <stdio.h>
#include <stdlib.h>

// 定义非零元素节点结构
typedef struct OLNode {
    int row, col;    // 非零元素的行和列
    int value;       // 非零元素的值
    struct OLNode *right, *down;  // 指向右边和下方的指针
} OLNode, *OLink;

// 定义十字链表结构
typedef struct {
    OLink *rowHead, *colHead;  // 行和列头指针数组
    int rows, cols, nums;      // 矩阵的行数、列数和非零元素个数
} CrossList;

// 创建十字链表
void CreateCrossList(CrossList *M) {
    int m, n, t;
    int i, j, e;
    OLNode *p, *q;

    printf("输入矩阵的行数、列数和非零元素个数: ");
    scanf("%d %d %d", &m, &n, &t);
    M->rows = m;
    M->cols = n;
    M->nums = t;

    // 初始化行列头指针数组
    M->rowHead = (OLink*)malloc((m + 1) * sizeof(OLink));
    M->colHead = (OLink*)malloc((n + 1) * sizeof(OLink));
    for (i = 0; i <= m; i++) M->rowHead[i] = NULL;
    for (j = 0; j <= n; j++) M->colHead[j] = NULL;

    // 输入非零元素
    printf("输入非零元素的行号、列号和值:\n");
    for (int k = 0; k < t; k++) {
        scanf("%d %d %d", &i, &j, &e);
        p = (OLNode*)malloc(sizeof(OLNode));
        p->row = i;
        p->col = j;
        p->value = e;
        p->right = p->down = NULL;

        // 插入到行链表
        if (M->rowHead[i] == NULL || M->rowHead[i]->col > j) {
            p->right = M->rowHead[i];
            M->rowHead[i] = p;
        } else {
            for (q = M->rowHead[i]; q->right && q->right->col < j; q = q->right);
            p->right = q->right;
            q->right = p;
        }

        // 插入到列链表
        if (M->colHead[j] == NULL || M->colHead[j]->row > i) {
            p->down = M->colHead[j];
            M->colHead[j] = p;
        } else {
            for (q = M->colHead[j]; q->down && q->down->row < i; q = q->down);
            p->down = q->down;
            q->down = p;
        }
    }
}

// 打印十字链表
void PrintCrossList(CrossList M) {
    OLNode *p;
    for (int i = 1; i <= M.rows; i++) {
        p = M.rowHead[i];
        while (p) {
            printf("(%d, %d, %d) ", p->row, p->col, p->value);
            p = p->right;
        }
        printf("\n");
    }
}

int main() {
    CrossList M;
    CreateCrossList(&M);
    printf("十字链表表示的稀疏矩阵:\n");
    PrintCrossList(M);
    return 0;
}