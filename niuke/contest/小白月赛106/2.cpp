#include <stdio.h>
/*
题目要求：
1. 构造n*n的矩阵
2. 每行每个数最多出现一次
3. 任意两不同行只有一个交集
4. 矩阵中每个元素出现次数小于等于2
5. 集合中元素为1到1E6之间

输出格式(n=3):
1 2 3
3 4 5
1 5 6
*/

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                // 第一行：1,2,3
                printf("%d ", j + 1);
            }
            else if (i == 1)
            {
                // 第二行：3,4,5
                printf("%d ", j + 3);
            }
            else
            {
                // 第三行：1,5,6
                if (j == 0)
                    printf("1 ");
                else if (j == 1)
                    printf("5 ");
                else
                    printf("6 ");
            }
        }
        printf("\n");
    }
    return 0;
}