#include <bits/stdc++.h> // 包含C++标准库

using namespace std; // 使用标准命名空间

#define mp make_pair // 定义make_pair的简写
#define pb push_back // 定义push_back的简写
#define fi first // 定义first的简写
#define se second // 定义second的简写
#define li long long // 定义long long的简写
#define pii pair<int, int> // 定义pair<int,int>的简写
#define vi vector<int> // 定义vector<int>的简写

#define forn(i, n) for (int i = 0; i < (int)n; i++) // 定义从0到n-1的循环宏
#define fore(i, b, e) for (int i = (int)b; i <= (int)e; i++) // 定义从b到e的循环宏
#define all(x) (x).begin(), (x).end() // 定义容器的begin和end迭代器

int ans = 0; // 存储最终答案
vector<vi> edges; // 存储图的邻接表
vi f; // 存储每个节点的状态值

void dfs(int v, int p) // 深度优先搜索函数，v是当前节点，p是父节点
{
    for (int u : edges[v]) // 遍历当前节点的所有邻接点
    {
        if (u != p) // 如果邻接点不是父节点
        {
            dfs(u, v); // 递归处理子节点
        }
    }
    f[v] = 1; // 初始化当前节点的状态值为1
    if (edges[v].size() >= 4) // 如果当前节点的度数大于等于4
    {
        vi children; // 存储子节点的状态值
        for (int u : edges[v]) // 遍历所有邻接点
        {
            if (u != p) // 如果不是父节点
            {
                children.pb(f[u]); // 添加子节点的状态值
            }
            else
            {
                children.pb(1); // 父节点贡献值为1
            }
        }
        sort(all(children), greater<int>()); // 对子节点状态值降序排序
        forn(j, 3) // 选择前3大的值
        {
            f[v] += children[j]; // 累加到当前节点的状态值
        }
        int here = 1; // 计算包含4个子节点的路径长度
        forn(j, 4)
        {
            here += children[j];
        }
        ans = max(ans, here); // 更新最大答案
    }
    else if (p == -1) // 如果是根节点
    {
        for (int u : edges[v]) // 遍历所有子节点
        {
            f[v] = max(f[v], f[u] + 1); // 更新根节点状态值
        }
    }
    // printf("f[%d] = %d edges count = %d\n", v, f[v], (int)edges[v].size());
    ans = max(ans, f[v] + (p == -1 ? 0 : 1)); // 更新最大答案
}

int main()
{
    int n; // 节点数量
    cin >> n;
    edges.resize(n + 1); // 初始化邻接表大小
    forn(i, n - 1) // 读入n-1条边
    {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v); // 添加无向边
        edges[v].pb(u);
    }
    f.resize(n + 1); // 初始化状态数组大小
    dfs(1, -1); // 从节点1开始深度优先搜索
    if (ans < 5) // 如果最大路径长度小于5
    {
        ans = -1; // 输出-1
    }
    cout << ans; // 输出答案
}
