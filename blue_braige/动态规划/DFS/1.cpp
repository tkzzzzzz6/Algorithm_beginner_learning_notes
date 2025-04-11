#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20;
int n;
bool st[N]; // 使用bool数组来标记是否选择某个数字

// DFS生成所有子集
void dfs(int x)
{
    // 到达叶子节点，输出当前选择的数字
    if (x > n)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (st[i])
                cout << i << " ";
        }
        cout << endl;
        return;
    }

    // 不选择当前数字
    st[x] = false;
    dfs(x + 1);

    // 选择当前数字
    st[x] = true;
    dfs(x + 1);
    st[x] = false; // 回溯时恢复状态
}

int main()
{
    cin >> n;

    // 输入验证
    if (n <= 0 || n >= N)
    {
        cout << "Invalid input!" << endl;
        return 1;
    }

    dfs(1);
    return 0;
}