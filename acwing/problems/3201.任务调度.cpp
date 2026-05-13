/*
 * @acwing app=acwing.cn id=3204 lang=C++
 *
 * 3201. 任务调度
 */

// @acwing code start
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 50, M = 210, INF = 0x3f3f3f3f;
// c[i][0]: 任务 i 用 1 个 CPU 的耗时 a_i
// c[i][1]: 任务 i 用 1 个 CPU + GPU 的耗时 c_i
// c[i][2]: 任务 i 使用 GPU 时的最优耗时 min(b_i, d_i)
int c[N][3];
// f[cur][i][j][k]: 处理到当前任务时，三类资源累计时间分别为 i,j,k 的最小“额外代价”
// 这里用滚动数组，cur 只有 0/1 两层
int f[2][M][M][M];

int main() {
    int n; // 任务数量
    cin >> n;
    int m = 0, m2 = 0; // m: a_i 总和上界, m2: 奇数下标任务的 a_i 和（用于压缩上界）
    for (int i = 1; i <= n; ++i) {
        int x, y, z, t; // 输入的 a_i, b_i, c_i, d_i
        cin >> x >> y >> z >> t;
        c[i][0] = x, c[i][1] = z, c[i][2] = min(y, t);
        m += x;
        if (i % 2)
            m2 += x;
    }
    m = max(m2, m - m2); // 这里简单得按奇偶性分成两组即可
    memset(f, 0x3f, sizeof f);
    f[0][0][0][0] = 0;

    for (int u = 1; u <= n; ++u) { // 枚举任务编号
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= m; ++k) {
                    int &v = f[u & 1][i][j][k]; // 当前层状态引用
                    if (k > j)
                        v = INF;
                    else {
                        register int x = c[u][0], y = c[u][1], z = c[u][2], t = (u - 1) & 1;
                        // t: 上一层滚动数组下标
                        // x,y,z: 当前任务在不同资源方案下的耗时参数
                        v = f[t][i][j][k] + z;
                        if (i >= x)
                            v = min(v, f[t][i - x][j][k]);
                        if (j >= x)
                            v = min(v, f[t][i][j - x][k]);
                        if (i >= y && k >= y)
                            v = min(v, f[t][i - y][j][k - y]);
                        if (j >= y && k >= y)
                            v = min(v, f[t][i][j - y][k - y]);
                    }
                }
            }
        }
    }

    int res = INF; // 最终最小完工时间
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j)
            for (int k = 0; k <= m; ++k)
                res = min(res, f[n & 1][i][j][k] + max(i, max(j, k)));

    cout << res << endl;

    return 0;
}

// @acwing code end
