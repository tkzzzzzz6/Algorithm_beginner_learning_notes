#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 使用计数排序,因为n是范围上限,所以开一个n+1大小的数组记录每个数出现的次数
    int count[2000001] = {0}; // 题目n最大为2000000

    // 统计每个数出现的次数
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        count[x]++;
    }

    // 按顺序输出
    for (int i = 1; i <= n; i++)
    {
        while (count[i]--)
        {
            cout << i << " ";
        }
    }

    return 0;
}