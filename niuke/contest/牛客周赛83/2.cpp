#include <iostream>
#include <vector>
using namespace std;

/**
 * 解决石子谜题问题
 *
 * 要求：放置石子使得相邻格子中的石子数之差的绝对值恰好为1
 *
 * 思路：当n较大时，使用1,2,3,...,n的方案会超过3n颗石子
 * 改进方案：使用交替的方式放置石子，如1,2,1,2,...或2,1,2,1,...
 * 这样每个相邻格子的石子数之差的绝对值仍然是1，但总石子数不会超过3n
 */
void solveStonesPuzzle(int n)
{
    // 使用交替的方式放置石子
    for (int i = 0; i < n; i++)
    {
        // 交替输出1和2
        cout << (i % 2 == 0 ? 1 : 2);
        if (i < n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T; // 读取测试用例数量

    while (T--)
    {
        int n;
        cin >> n; // 读取空格子数量

        solveStonesPuzzle(n);
    }

    return 0;
}
