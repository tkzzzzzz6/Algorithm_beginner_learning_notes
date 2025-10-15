#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN]; // 邻接表表示树
int dist[MAXN];        // 用于BFS计算距离

// 计算从start到所有其他点的距离，并返回距离数组
void bfs(int start)
{
    fill(dist, dist + MAXN, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

// 找出节点u到节点v的最短路径上的下一个节点
int next_on_path(int u, int v)
{
    if (u == v)
        return u; // 已经到达目标

    // 计算从目标v到所有点的距离
    bfs(v);

    // 选择u的邻居中距离v最近的
    int min_dist = INT_MAX;
    int next_node = -1;

    for (int neighbor : adj[u])
    {
        if (dist[neighbor] < min_dist)
        {
            min_dist = dist[neighbor];
            next_node = neighbor;
        }
    }

    return next_node;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // 读入树的边
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 如果起始点只有一个邻居，那么Saki无法生存第一回合
    if (adj[k].size() <= 1)
    {
        cout << 0 << endl;
        return 0;
    }

    // 模拟游戏过程
    int saki = k; // Saki的初始位置
    int miku = k; // Miku的初始位置
    int rounds = 0;

    while (true)
    {
        // 尝试Saki的所有可能移动
        bool can_survive = false;
        int best_next_saki = -1;
        int best_next_miku = -1;

        for (int next_saki : adj[saki])
        {
            // 对于每个可能的下一步位置，尝试所有可能的替身位置
            for (int decoy : adj[next_saki])
            {
                if (decoy == next_saki)
                    continue; // 替身不能和Saki在同一位置

                // 计算Miku的下一步位置
                int next_miku;
                if (miku == decoy)
                {
                    next_miku = miku; // Miku停留不动
                }
                else
                {
                    next_miku = next_on_path(miku, decoy);
                }

                // 如果Saki的新位置不与Miku的新位置重合，则可以继续游戏
                if (next_saki != next_miku)
                {
                    can_survive = true;
                    best_next_saki = next_saki;
                    best_next_miku = next_miku;
                    break;
                }
            }
            if (can_survive)
                break;
        }

        // 如果无法找到安全的移动方式，下一回合将无法进行
        if (!can_survive)
        {
            break;
        }

        // 执行最佳移动
        saki = best_next_saki;
        miku = best_next_miku;
        rounds++; // 成功完成一个回合

        // 如果回合结束后Saki与Miku在同一位置，游戏结束
        if (saki == miku)
        {
            break;
        }
    }

    cout << rounds << endl;
    return 0;
}