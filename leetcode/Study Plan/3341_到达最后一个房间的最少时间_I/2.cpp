#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
    struct State{
        int x, y, dis;
        State(int x, int y, int dis) : x(x), y(y), dis(dis) {};
        bool operator<(const State &rth) const{
            return dis > rth.dis;
        }
    };

public:
    const int inf = 0x3f3f3f3f;
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();

        vector<vector<int>> d(n, vector<int>(m, inf));
        vector<vector<int>> v(n, vector<int>(m, 0));

        // 定义方向
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        d[0][0] = 0;
        priority_queue<State> q;
        q.push(State(0, 0, 0));

        while(q.size()){
            State s = q.top();
            q.pop();
            //如果该点已经访问    
            if(v[s.x][s.y])
                continue;
            //标记为已经访问
            v[s.x][s.y] = 1;

            //遍历四个方向
            for (int i = 0; i < 4; ++i) {
                int nx = s.x + dirs[i][0];
                int ny = s.y + dirs[i][1];
                //检查是否越界
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                //计算到达新点的时间
            }



            //找到更短时间,加入优先队列

            //返回最短时间
        }
        }
};