#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution
{
public:
    // 使用Dijkstra算法求解网络延迟时间
    // times: 有向图的边列表，每个元素为 [起点,终点,权重]
    // n: 节点数量
    // k: 起始节点
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // 定义无穷大值，使用INT_MAX/2避免加法溢出
        const int inf = INT_MAX / 2;
        // 构建邻接矩阵表示的图，初始化为无穷大
        vector<vector<int>> g(n, vector<int>(n, inf));
        // 填充图的边权重
        for (auto &t : times)
        {
            int x = t[0] - 1, y = t[1] - 1;  // 节点编号从0开始
            g[x][y] = t[2];  // 设置边的权重
        }

        // dist数组存储从起点k到各个节点的最短距离
        vector<int> dist(n, inf);
        dist[k - 1] = 0;  // 起点到自身的距离为0
        // used数组标记节点是否已确定最短路径
        vector<int> used(n);
        
        // Dijkstra算法主循环
        for (int i = 0; i < n; ++i)
        {
            // 找到未使用节点中距离最小的节点x
            int x = -1;
            for (int y = 0; y < n; ++y)
            {
                if (!used[y] && (x == -1 || dist[y] < dist[x]))
                {
                    x = y;
                }
            }
            used[x] = true;  // 标记节点x已使用
            
            // 更新通过节点x可以到达的其他节点的距离
            for (int y = 0; y < n; ++y)
            {
                dist[y] = min(dist[y], dist[x] + g[x][y]);
            }
        }

        // 找到所有节点中的最大延迟时间
        int ans = *max_element(dist.begin(), dist.end());
        // 如果存在无法到达的节点，返回-1
        return ans == inf ? -1 : ans;
    }
};
