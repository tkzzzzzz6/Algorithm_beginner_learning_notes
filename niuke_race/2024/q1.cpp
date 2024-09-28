#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;

    int y;
    for (int i = 0; i < 3; i++)
    {
        int y;  // 读取要进行异或运算的数
        y ^= x; // 执行异或运算并更新结果
    }

    cout << y << endl; // 输出最终结果
}