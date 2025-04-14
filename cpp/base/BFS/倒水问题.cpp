#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

// 状态数组最大值
const int MAX_STATES = 360;
const int MAX_CUPS = 4;

// target：目标水量
// states[i][j]：第i个状态中第j个杯子的水量
// visited[a][b][c]：标记是否访问过状态(a,b,c)
// cupCapacity：每个杯子的容量
int target;
int states[MAX_STATES][MAX_CUPS];
int visited[4][8][11];
const int cupCapacity[MAX_CUPS] = {0, 3, 7, 9};

int main()
{
    // 输入目标水量
    if (scanf_s("%d", &target, sizeof(int)) != 1)
    {
        printf("输入错误\n");
        return 1;
    }

    // 初始化数组
    memset(states, 0, sizeof(states));
    memset(visited, 0, sizeof(visited));

    // 设置初始状态：第三个杯子装满10升水
    states[1][1] = 0;
    states[1][2] = 0;
    states[1][3] = 10;
    states[1][4] = 0;
    visited[0][0][10] = 1;

    int currentState = 0, totalStates = 1;

    // BFS搜索所有可能的倒水状态
    while (currentState < totalStates)
    {
        ++currentState;

        // 尝试在所有杯子之间倒水
        for (int from = 0; from < MAX_CUPS; ++from)
        {
            for (int to = 0; to < MAX_CUPS; ++to)
            {
                // 跳过相同的杯子和无效的倒水操作
                if (from == to || states[currentState][from] <= 0 ||
                    states[currentState][to] >= cupCapacity[to])
                {
                    continue;
                }

                // 创建新状态
                ++totalStates;
                if (totalStates >= MAX_STATES)
                {
                    printf("状态空间溢出\n");
                    return 1;
                }

                // 复制当前状态
                for (int k = 0; k < MAX_CUPS; ++k)
                {
                    states[totalStates][k] = states[currentState][k];
                }

                // 执行倒水操作
                int pourAmount = min(states[totalStates][from],
                                     cupCapacity[to] - states[totalStates][to]);
                states[totalStates][from] -= pourAmount;
                states[totalStates][to] += pourAmount;

                // 检查是否为新状态
                if (!visited[states[totalStates][1]]
                            [states[totalStates][2]]
                            [states[totalStates][3]])
                {
                    visited[states[totalStates][1]]
                           [states[totalStates][2]]
                           [states[totalStates][3]] = 1;
                    states[totalStates][4]++;

                    // 检查是否达到目标
                    if (states[totalStates][3] == target)
                    {
                        printf("%d", states[totalStates][4]);
                        return 0;
                    }
                }
                else
                {
                    --totalStates;
                }
            }
        }
    }

    printf("%d", -1); // 无解
    return 0;
}
