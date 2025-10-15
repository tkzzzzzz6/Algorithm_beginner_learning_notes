#include <bits/stdc++.h>
// 定义一个简化的循环宏
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

// 定义一个表示无穷大的常量
int inf = 1000000010;

int main()
{
    // 读入矩阵大小n
    int n;
    cin >> n;
    // 创建n*n的字符矩阵c用于存储输入
    vector<vector<char>> c(n, vector<char>(n));
    rep(i, n) rep(j, n) cin >> c[i][j];
    
    // 创建n*n的距离矩阵a，初始化为无穷大
    vector<vector<int>> a(n, vector<int>(n, inf));
    // 创建队列用于BFS搜索
    queue<pair<int, int>> que;
    
    // 对角线元素距离初始化为0
    rep(i, n)
    {
        que.push({i, i});
        a[i][i] = 0;
    }
    
    // 直接相连的元素距离初始化为1
    rep(i, n) rep(j, n)
    {
        if (i == j or c[i][j] == '-')
            continue;
        que.push({i, j});
        a[i][j] = 1;
    }
    
    // BFS搜索计算所有点对之间的最短距离
    while (!que.empty()) // 当队列不为空时继续搜索
    {
        auto q = que.front(); // 获取队首元素
        que.pop(); // 弹出队首元素
        int i = q.first, j = q.second; // 获取当前处理的点对(i,j)的坐标
        
        // 遍历所有可能的新点对(k,l)
        rep(k, n) rep(l, n) 
        {
            // 判断是否可以通过当前点对(i,j)构建到新点对(k,l)的路径:
            // 1. c[k][i]不是'-' - 表示k到i有边
            // 2. c[j][l]不是'-' - 表示j到l有边
            // 3. c[k][i] == c[j][l] - 两条边的字符相同
            // 4. a[k][l] == inf - 点对(k,l)还未被访问过
            if (c[k][i] != '-' && c[j][l] != '-' && c[k][i] == c[j][l] && a[k][l] == inf)
            {
                // 新路径的距离 = 当前点对的距离 + 2
                // +2是因为需要经过两条新的边(k->i和j->l)
                a[k][l] = a[i][j] + 2;
                que.push({k, l}); // 将新的点对加入队列以继续搜索
            }
        }
    }
    
    // 输出结果矩阵
    rep(i, n)
    {
        rep(j, n)
        {
            // 如果距离仍为无穷大，输出-1，否则输出实际距离
            cout << (a[i][j] == inf ? -1 : a[i][j]) << " \n"[j == n - 1];
        }
    }
}
