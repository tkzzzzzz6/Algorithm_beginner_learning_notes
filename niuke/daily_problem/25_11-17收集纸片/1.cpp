// TSP问题：需要枚举所有路径找最短路径
#include <bits/stdc++.h>
#define il inline
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

typedef struct
{
    int x, y;
} Node;

vector<Node> nodes;
vector<int> vis;
int n;
ll ans;

// 计算两点之间的曼哈顿距离
il int dist(int i, int j)
{
    return abs(nodes[i].x - nodes[j].x) + abs(nodes[i].y - nodes[j].y);
}

// DFS枚举所有路径
il void dfs(int cur, int cnt, ll sum)
{
    if (cnt == n)
    {
        // 收集完所有纸片，返回起点
        sum += dist(cur, 0);
        ans = min(ans, sum);
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i, cnt + 1, sum + dist(cur, i));
            vis[i] = 0;
        }
    }
}

il void solve()
{
    nodes.clear(); // 清空节点数组
    int r, c;
    cin >> r >> c;
    // 添加初始位置节点
    int xs, ys;
    cin >> xs >> ys;
    nodes.push_back({xs, ys});
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        nodes.push_back({x, y});
    }
    vis.assign(nodes.size(), 0); // 重置vis数组
    ans = inf;
    vis[0] = 1;   // 起点已访问
    dfs(0, 0, 0); // 从起点开始，已访问0个纸片，当前距离为0
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
