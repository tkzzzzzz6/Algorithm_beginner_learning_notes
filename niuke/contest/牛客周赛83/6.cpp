#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// 定义一个结构体Node，用于存储节点信息
struct Node {
    int x, y, nowT, abi; // x, y表示坐标，nowT表示当前时间，abi表示能力
    // 重载小于运算符，用于优先队列的比较
    bool operator<(const Node& y) const {
        return y.nowT < nowT; // 优先队列中时间较小的节点优先级高
    }
};

// 定义求解函数
void solve() {
    int n, m, t; // 定义变量n, m, t分别表示行数、列数和时间
    cin >> n >> m >> t; // 输入行数、列数和时间
    ++t; // 我们默认水流直接进入新节点，所以t自增比较方便
    // 定义一个字符型二维向量G，用于存储地图信息，初始化为'^'
    vector<vector<char>> G(n + 5, vector<char>(m + 5, '^'));
    pair<int, int> stp, enp; // 定义起点和终点的坐标
    // 遍历地图，读取每个位置的字符
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> G[i][j]; // 输入地图信息
            if (G[i][j] == '*') stp = {i, j}; // 如果是起点，记录坐标
            if (G[i][j] == '%') enp = {i, j}; // 如果是终点，记录坐标
        }
    }
    // 定义优先队列q，用于存储节点
    priority_queue<Node> q;
    // 将起点信息压入队列，初始时间为0，能力为1
    q.push({stp.first, stp.second, 0, 1});
    // 定义一个布尔型二维向量vis，用于标记访问过的节点
    vector<vector<bool>> vis(n + 5, vector<bool>(m + 5, 0));
    // 当队列不为空时，进行循环
    while (!q.empty()) {
        // 取出队列顶部的节点信息
        auto [x, y, nowT, can] = q.top();
        q.pop(); // 弹出队列顶部元素
        if (can != 1) if (vis[x][y]) continue; // 如果能力不为1且已访问过，跳过
        vis[x][y] = true; // 标记当前节点为已访问
        if (G[x][y] == '%') { // 如果到达终点
            cout << nowT << endl; // 输出当前时间
            return; // 结束函数
        }
        // 如果下方是墙
        if (G[x + 1][y] == '#') {
            // 如果能力为1且下方未访问过，将下方节点压入队列
            if (can and !vis[x + 1][y]) q.push({x + 1, y, nowT + t, 1}); // 塞
            // 如果右方在范围内且不是墙，将右方节点压入队列
            if (y + 1 <= m and G[x][y + 1] != '#') q.push({x, y + 1, nowT + 1, 0}); // 左右扩散判定
            // 如果左方在范围内且不是墙，将左方节点压入队列
            if (y - 1 >= 1 and G[x][y - 1] != '#') q.push({x, y - 1, nowT + 1, 0});
        } else {
            // 如果下方在范围内，将下方节点压入队列
            if (x + 1 <= n) q.push({x + 1, y, nowT + 1, 1}); // 垂直扩散判定
        }
    }
    cout << -1 << endl; // 如果无法到达终点，输出-1
    return; // 结束函数
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
