class Solution
{
    // 定义状态结构体，用于优先队列
    struct State
    {
        int x;      // 当前x坐标
        int y;      // 当前y坐标
        int dis;    // 到达该点的最短时间
        State(int x, int y, int dis) : x(x), y(y), dis(dis) {};
        // 重载小于运算符，用于优先队列排序（小根堆）
        bool operator<(const State &rth) const
        {
            return dis > rth.dis;
        }
    };

public:
    const int inf = 0x3f3f3f3f;  // 定义无穷大值
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();
        // d数组存储到达每个点的最短时间
        vector<vector<int>> d(n, vector<int>(m, inf));
        // v数组标记点是否已访问
        vector<vector<int>> v(n, vector<int>(m, 0));

        // 定义四个方向的移动：下、上、右、左
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        d[0][0] = 0;  // 起点时间为0
        priority_queue<State> q;  // 优先队列，按时间排序
        q.push(State(0, 0, 0));  // 将起点加入队列

        while (q.size())
        {
            State s = q.top();
            q.pop();
            // 如果该点已访问，跳过
            if (v[s.x][s.y])
            {
                continue;
            }
            v[s.x][s.y] = 1;  // 标记为已访问
            // 遍历四个方向
            for (int i = 0; i < 4; i++)
            {
                int nx = s.x + dirs[i][0];
                int ny = s.y + dirs[i][1];
                // 检查是否越界
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    continue;
                }
                // 计算到达新点的时间：当前点时间、新点移动时间的较大值 + 1
                int dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1;
                // 如果找到更短的时间，更新并加入队列
                if (d[nx][ny] > dist)
                {
                    d[nx][ny] = dist;
                    q.push(State(nx, ny, dist));
                }
            }
        }
        return d[n - 1][m - 1];  // 返回到达终点的最短时间
    }
};
