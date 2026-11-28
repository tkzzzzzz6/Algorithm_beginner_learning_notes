#include <stdio.h>

int main()
{
    int i, j, k, n, m, q, mask;
    scanf("%d %d %d", &n, &m, &q);
    char grid[8][8];     // 存储草地初始状态
    char plans[8][8][8]; // 存储所有计划

    // 读入草地初始状态
    for (i = 0; i < n; i++)
    {
        scanf("%s", grid[i]);
    }

    // 读入所有计划
    for (k = 0; k < q; k++)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%s", plans[k][i]);
        }
    }

    int min_cnt = 1000; // 初始化最小计划数为一个大数
    int best_mask = -1; // 最优解的掩码

    // 枚举所有计划组合 (掩码mask)
    for (mask = 0; mask < (1 << q); mask++)
    {
        int result[8][8] = {0}; // 存储组合后的烟花位置

        // 叠加选中的计划
        for (k = 0; k < q; k++)
        {
            if (mask & (1 << k))
            { // 检查第k个计划是否被选中
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < m; j++)
                    {
                        if (plans[k][i][j] == '1')
                        {
                            result[i][j] = 1;
                        }
                    }
                }
            }
        }

        // 检查组合是否满足条件
        int valid = 1;
        for (i = 0; i < n && valid; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    if (result[i][j] != 0)
                    { // 杂物位置不能有烟花
                        valid = 0;
                        break;
                    }
                }
                else
                {
                    if (result[i][j] != 1)
                    { // 非杂物位置必须有烟花
                        valid = 0;
                        break;
                    }
                }
            }
        }

        if (valid)
        {
            // 计算当前组合的计划数
            int cnt = 0;
            for (k = 0; k < q; k++)
            {
                if (mask & (1 << k))
                    cnt++;
            }
            // 更新最小计划数及最优掩码
            if (cnt < min_cnt)
            {
                min_cnt = cnt;
                best_mask = mask;
            }
        }
    }

    if (best_mask == -1)
    {
        printf("-1\n");
    }
    else
    {
        // 输出计划数量
        printf("%d\n", min_cnt);
        // 输出选中的计划编号（升序）
        int first = 1;
        for (k = 0; k < q; k++)
        {
            if (best_mask & (1 << k))
            {
                if (first)
                {
                    printf("%d", k + 1);
                    first = 0;
                }
                else
                {
                    printf(" %d", k + 1);
                }
            }
        }
        printf("\n");
    }

    return 0;
}