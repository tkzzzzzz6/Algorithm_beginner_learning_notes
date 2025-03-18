#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// g数组存储灯的状态，backup为备份数组，res存储操作结果（按下哪些开关）
int g[5][6], backup[5][6], res[5][6];                   
// dx和dy数组用于表示自身及四个方向（上、右、下、左、自身）的坐标偏移
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0}; 

// 按下(a,b)位置的开关
void turn(int a, int b)
{ 
    res[a][b] = 1;  // 记录在(a,b)位置按下了开关
    for (int i = 0; i < 5; ++i)
    {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x < 0 || y < 0 || x >= 5 || y >= 6)
            continue; // 如果坐标超出边界则跳过
        g[x][y] ^= 1; // 使用异或运算切换灯的状态（0变1，1变0）
    }

    return;
}

int main()
{
    int n;
    cin >> n;  // 输入谜题数量
    for (int p = 1; p <= n; ++p)
    { // 处理每个谜题
        
        // 输入灯的初始状态
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 6; ++j)
            {
                cin >> g[i][j];
            }
        memcpy(backup, g, sizeof g);  // 备份初始状态

        // 枚举第一行所有可能的按法（2^6=64种可能）
        for (int op = 0; op < (1 << 6); ++op)
        { 
            // 恢复初始状态
            memcpy(g, backup, sizeof backup); 
            memset(res, 0, sizeof res);       // 清空操作记录
                                        
            // 处理第一行的按法
            for (int j = 0; j < 6; ++j)
            {
                if (op >> j & 1)  // 检查第j位是否为1（是否按下第j个开关）
                    turn(0, j);   // 按下第一行第j列的开关
            }

            // 处理第2-5行：如果上一行有亮着的灯，则必须按下当前行对应位置的开关
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 6; ++j)
                {
                    if (g[i][j] == 1)  // 如果当前位置的灯亮着
                        turn(i + 1, j); // 按下下一行对应位置的开关
                }

            // 检查最后一行是否全部熄灭
            bool dark = true;
            for (int i = 0; i < 6; ++i)
                if (g[4][i] == 1)  // 如果最后一行有灯亮着
                {
                    dark = false;  // 标记为未解决
                    break;
                }

            // 如果找到解决方案（最后一行全部熄灭）
            if (dark)
            {
                cout << "PUZZLE #" << p << endl;  // 输出谜题编号
                // 输出解决方案（哪些开关需要按下）
                for (int i = 0; i < 5; ++i)
                {
                    for (int j = 0; j < 6; ++j)
                        cout << res[i][j] << ' ';
                    cout << endl;
                }
                break;  // 找到解决方案后跳出循环，处理下一个谜题
            }
        }
    }
    return 0;
}