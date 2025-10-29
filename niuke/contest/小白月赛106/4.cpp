#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 205;
const int INF = 0x3f3f3f3f;

struct State {
    int pos, k, dist;
    State(int p, int kk, int d) : pos(p), k(kk), dist(d) {}
};

int n, K, a, b, x, y;
int vis[MAXN][MAXK];

int bfs() {
    memset(vis, 0, sizeof(vis));
    queue<State> q;
    
    // 检查输入范围
    if(a < 1 || a > n || b < 1 || b > n || K < 0 || K >= MAXK) {
        return -1;
    }
    
    q.push(State(a, K, 0));
    vis[a][K] = 1;

    while(!q.empty()) {
        State cur = q.front();
        q.pop();

        int pos = cur.pos;
        int k = cur.k;
        int dist = cur.dist;

        if(pos == b) return dist;

        // 顺时针移动x
        int next_pos = (pos + x - 1 + n) % n + 1;
        if(next_pos >= 1 && next_pos <= n && k >= 0 && k < MAXK && !vis[next_pos][k]) {
            vis[next_pos][k] = 1;
            q.push(State(next_pos, k, dist + 1));
        }

        // 逆时针移动y
        next_pos = ((pos - y - 1 + n) % n) + 1;
        if(next_pos >= 1 && next_pos <= n && k >= 0 && k < MAXK && !vis[next_pos][k]) {
            vis[next_pos][k] = 1;
            q.push(State(next_pos, k, dist + 1));
        }

        // 使用技能
        if(k > 0) {
            next_pos = (pos + n/2 - 1 + n) % n + 1;
            if(next_pos >= 1 && next_pos <= n && (k-1) >= 0 && (k-1) < MAXK && !vis[next_pos][k-1]) {
                vis[next_pos][k-1] = 1;
                q.push(State(next_pos, k-1, dist + 1));
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> K >> a >> b >> x >> y;
    
    // 检查输入范围
    if(n <= 0 || n >= MAXN) {
        cout << -1 << endl;
        return 0;
    }
    
    cout << bfs() << endl;
    return 0;
}