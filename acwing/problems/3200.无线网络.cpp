/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-11 15:07:55
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-11 19:33:28
 */
/*
 * @acwing app=acwing.cn id=3203 lang=C++
 *
 * 3200. 无线网络
 */

// @acwing code start
// 图论最短路问题
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 210, M = N * N; // n+m 最多 200个节点,最多 M 个边
int n, m, k, r;
// h[N]     // h[i] = 节点i的邻接表头指针（初值-1表示无邻接）
// e[M]     // e[j] = 第j条边指向的目标节点
// ne[M]    // ne[j] = 第j条边之后的下一条边的索引（形成链表）
// idx      // 当前边的编号计数器
int h[N], e[M], ne[M], idx; // 邻接表存储图
PII p[N]; // 存储所有路由器坐标
int dist[N][N]; // dist[x][y]:到路由器x用y个新路由器的最少步数

bool check(PII a, PII b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy <= (ll)r * r;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs() { 
    queue<PII> q;
    q.push({1, 0});
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;

    while (q.size()) {
        auto t = q.front();
        q.pop();

        // 遍历路由器 t.x 的所有邻接节点
        for (int i = h[t.x]; i != -1; i = ne[i]) { // i != -1 等价于 ~i 因为 -1 == ...1111, ~(-1) == ...0000 = 0
            int x = e[i]; //下一个节点
            int y = t.y; //继承当前使用的新路由器数
            if (x > n) // 下一节点是新增路由器
                ++y;
            if (y <= k) {  //不超过 k 个新路由器
                if (dist[x][y] > dist[t.x][t.y] + 1) {
                    dist[x][y] = dist[t.x][t.y] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    int res = 1e8;
    for (int i = 0; i <= k; ++i) {
        res = min(res, dist[2][i]); // 路由器 2 处,用 0~k个新路由器的最少步数
    }
    return res - 1; //因为这里求的中转数,步数 - 1 == 中转数
}

int main() {
    cin >> n >> m >> k >> r;
    memset(h, -1, sizeof h);
    // 存储节点
    for (int i = 1; i <= n; ++i)
        cin >> p[i].x >> p[i].y;
    for (int i = n + 1; i <= n + m; ++i)
        cin >> p[i].x >> p[i].y;

    for (int i = 1; i <= n+m; ++i) {
        for (int j = i + 1; j <= n + m; ++j)
            if (check(p[i], p[j]))
                add(i, j), add(j, i);
    }

    cout << bfs() << endl;
    return 0;
}
// @acwing code end
