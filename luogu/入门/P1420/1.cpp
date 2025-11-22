#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 1, max = 1; // 从1开始，因为单个数字也算长度为1
    int prev, curr;

    // 读取第一个数
    cin >> prev;

    // 读取剩余的数
    for (int i = 1; i < n; i++)
    {
        cin >> curr;
        if (curr == prev + 1) // 检查是否为连续自然数
            ++cnt;
        else
            cnt = 1; // 重置为1，因为当前数字本身也算长度为1
        if (cnt > max)
            max = cnt;
        prev = curr;
    }

    cout << max;
    return 0;
}