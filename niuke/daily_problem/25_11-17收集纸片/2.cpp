#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int width, height;    // 地图的行数和列数（本题其实没用上）
        int startX, startY;   // 机器人起始位置
        int n;                // 纸片数量
        cin >> width >> height >> startX >> startY >> n;

        // points[0] 为起始点，points[1~n]为需要收集纸片的位置
        vector<pair<int, int>> points(n + 1);
        points[0] = {startX, startY};
        for (int i = 1; i <= n; ++i)
        {
            cin >> points[i].first >> points[i].second;
        }

        // 预处理每两个点之间的曼哈顿距离，dist[i][j] 表示第i和第j点之间距离
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                dist[i][j] = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
            }
        }

        // 枚举n个纸片的位置的排列（固定起点），order表示纸片编号的排列顺序
        vector<int> order(n);
        iota(order.begin(), order.end(), 1); // 1,2,3...n

        const int INF = 0x3f3f3f3f;
        int answer = INF; // 最短路径答案初始化为无穷大
        do
        {
            // 距离 = 起点到第一个纸片 + 每段纸片间距离
            int total = dist[0][order[0]];
            bool pruned = false; // 剪枝标志
            for (int i = 0; i + 1 < n; ++i)
            {
                total += dist[order[i]][order[i + 1]];
                // 剪枝：如果当前距离已经不优直接退出
                if (total >= answer)
                {
                    pruned = true;
                    break;
                }
            }
            if (pruned)
                continue;
            // 回到起点的距离
            total += dist[order.back()][0];
            // 记录最优解
            answer = min(answer, total);
        } while (next_permutation(order.begin(), order.end()));

        cout << "The shortest path has length " << answer << "\n";
    }
    return 0;
}