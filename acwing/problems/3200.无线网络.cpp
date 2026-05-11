/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-11 15:07:55
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-11 19:11:02
 */
/*
 * @acwing app=acwing.cn id=3203 lang=C++
 *
 * 3200. 无线网络
 */

// @acwing code start
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 210, M = N * N;
int n, m, k, r;
int h[N], e[M], ne[M], idx;
PII p[M];
int dist[N][N];

bool check(PII a, PII b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy <= r * r;
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

        for (int i = h[t.x]; ~i; i = ne[i]) {
            int x = e[i], y = t.y;
            if (x > n)
                ++y;
            if (y <= k) {
                if (dist[x][y] > dist[t.x][t.y] + 1) {
                    dist[x][y] = dist[t.x][t.y] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    int res = 1e8;
    for (int i = 0; i <= k; ++i) {
        res = min(res, dist[2][i]);
    }
    return res - 1;
}

int main() {
    cin >> n >> m >> k >> r;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; ++i)
        cin >> p[i].x >> p[i].y;
    for (int i = n + 1; i <= n + m; ++i)
        cin >> p[i].x >> p[i].y;

    for (int i = 1; i <= n; ++i) {
        for (int j = n + 1; j <= n + m; ++j)
            if (check(p[i], p[j]))
                add(i, j), add(j, i);
    }

    cout << bfs() << endl;
    return 0;
}
// @acwing code end
