/*
 * @acwing app=acwing.cn id=3208 lang=C++
 *
 * 3205. 最优配餐
 */

// @acwing code start
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1010;
queue<PII> q;

typedef struct {
    int x, y, c;
} Target;

Target tg[N * N];

bool g[N][N];
int dist[N][N];
int n, m, k, d;

void bfs() {
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    while (q.size()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int a = t.x + dx[i];
            int b = t.y + dy[i];

            if (a < 1 || a > n || b < 1 || b > n || g[a][b])
                continue;
            if (dist[a][b] > dist[t.x][t.y] + 1) {
                dist[a][b] = dist[t.x][t.y] + 1;
                q.push({a, b});
            }
        }
    }
}

int main() {
    // 提交cin 速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> d;
    memset(dist, 0x3f, sizeof dist);
    while (m--) {
        int x, y;
        cin >> x >> y;
        dist[x][y] = 0;
        q.push({x, y});
    }

    for (int i = 0; i < k; ++i) {
        cin >> tg[i].x >> tg[i].y >> tg[i].c;
    }

    while (d--) {
        int x, y;
        cin >> x >> y;
        g[x][y] = true;
    }

    bfs();

    ll res = 0;
    for (int i = 0; i < k; ++i) {
        res += dist[tg[i].x][tg[i].y] * tg[i].c;
    }

    cout << res << endl;

    return 0;
}

// @acwing code end
