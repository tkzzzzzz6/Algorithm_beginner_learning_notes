// 最小生成树的问题,我们先使用prim算法
// 实际上，这个题更像是TSP问题，使用状态压缩+记忆化搜索

#include <bits/stdc++.h>
#define il inline
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

// 定义点的坐标结构体
typedef struct
{
    int x, y;
} Node;

// 各种全局变量
vector<Node> nodes;                // 存储所有点（起点和所有纸片点）
vector<vector<int>> dist;          // 两两点之间的曼哈顿距离
vector<vector<int>> memo;          // 记忆化数组，用于状态压缩DP
int nBeepers, targetMask;          // 纸片数量和目标状态
const int INF_INT = 1e9;           // 无限大

// 状态压缩DP，pos表示当前在哪个点，mask表示已收集的点集合
int dfs(int pos, int mask)
{
    // 所有纸片都已收集，返回回到起点的距离
    if (mask == targetMask)
        return dist[pos][0];
    int &res = memo[pos][mask];
    if (res != -1)
        return res;
    int best = INF_INT;
    // 枚举所有还没收集的纸片，尝试到下一个点
    for (int i = 1; i <= nBeepers; ++i)
    {
        if (!(mask & (1 << (i - 1))))
        {
            // 递归到下一个状态，累加路径长度
            best = min(best, dist[pos][i] + dfs(i, mask | (1 << (i - 1))));
        }
    }
    return res = best;
}

// 单组输入处理
il void solve()
{
    nodes.clear();
    int r, c;
    cin >> r >> c;     // 地图行列，不用，但要求输入
    int xs, ys, n;
    cin >> xs >> ys;   // 机器人起点坐标
    nodes.push_back({xs, ys});
    cin >> n;          // 纸片数
    nBeepers = n;
    // 输入所有纸片的位置
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        nodes.push_back({x, y});
    }
    // 计算所有点之间的曼哈顿距离
    dist.assign(nBeepers + 1, vector<int>(nBeepers + 1, 0));
    for (int i = 0; i <= nBeepers; ++i)
    {
        for (int j = 0; j <= nBeepers; ++j)
        {
            dist[i][j] = abs(nodes[i].x - nodes[j].x) + abs(nodes[i].y - nodes[j].y);
        }
    }
    targetMask = (1 << nBeepers) - 1;            // 最终所有纸片都被收集的状态
    memo.assign(nBeepers + 1, vector<int>(1 << nBeepers, -1)); // 初始化记忆化数组
    int ans = dfs(0, 0);                         // 从起点出发，收集所有纸片
    cout << "The shortest path has length " << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
