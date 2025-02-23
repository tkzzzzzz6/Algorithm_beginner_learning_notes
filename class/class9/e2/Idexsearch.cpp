#include <stdio.h>
#define MAXL 100 // 数据表的最大长度
#define MAXI 20  // 索引表的最大长度
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
    KeyType key;
    InfoType data;
    // KeyType为关键字的数据类型
    // 其他数据
} NodeType;
typedef NodeType SeqList[MAXL]; // 顺序表类型

typedef struct
{
    KeyType key;
    int link;

    // 指向对应块的起始下标
} IdxType;
typedef IdxType IDX[MAXI]; // 索引表类型

int IdxSearch(IDX I, int m, SeqList R, int n, KeyType k)
{
    // 块间采用折半查找，块内采用顺序查找
    int left = 0, right = m - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (k == I[mid].key)
        {
            // 找到索引值后，还需要在对应的块中定位具体位置
            int j = I[mid].link;
            while (j < n && R[j].key != k)
                j++;
            if (j < n)
                return j + 1; // 返回实际位置（从1开始计数）
        }
        else if (k < I[mid].key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}

int main()
{
    int i, n = 25, m = 5, j;
    SeqList R;
    IDX I = {{14, 0}, {34, 5}, {66, 10}, {85, 15}, {100, 20}};
    KeyType a[] = {8, 14, 6, 9, 10, 22, 34, 18, 19, 31, 40, 38, 54, 66, 46, 71, 78, 68, 80, 85, 100, 94, 88, 96, 87};

    // 将数组a中的数据初始化到R中
    for (i = 0; i < n; i++)
    {
        R[i].key = a[i];
    }

    KeyType x;
    scanf("%d", &x);
    j = IdxSearch(I, m, R, n, x);

    if (j != 0)
        printf("%d是第%d个数据\n", x, j);
    else
        printf("未找到%d\n", x);
    return 0;
}