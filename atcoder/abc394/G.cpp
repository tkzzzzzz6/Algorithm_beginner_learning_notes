// 包含C++标准库和atcoder的并查集库
#include <bits/stdc++.h>
#include <atcoder/dsu>

// 使用标准命名空间和atcoder命名空间
using namespace std;
using namespace atcoder;

// 定义常量
#define H 500          // 最大高度
#define W 500          // 最大宽度
#define Q (int)2e+5    // 最大查询次数
#define F (int)1e+6    // 最大权值

int main(void)
{
    int h, w, q;                   // h,w为网格大小,q为查询次数
    int f[H][W];                   // f[i][j]存储网格中每个位置的权值
    int a[Q], b[Q], y[Q];          // 每个查询的起点坐标(a,b)和权值y
    int c[Q], d[Q], z[Q];          // 每个查询的终点坐标(c,d)和权值z
    int l[Q], r[Q];                // 二分查找的左右边界
    vector<pair<int, int>> e[F + 1];    // e[i]存储权值为i的边
    vector<int> check[F + 1];           // check[i]存储需要在权值i处检查的查询

    // 读入网格大小
    cin >> h >> w;
    // 读入网格中的权值
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> f[i][j];
    // 读入查询次数和查询信息
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i] >> y[i] >> c[i] >> d[i] >> z[i];
        a[i]--, b[i]--, c[i]--, d[i]--;  // 坐标从0开始
    }

    // 构建边集合
    // 添加竖直方向的边
    for (int i = 0; i < h - 1; i++)
        for (int j = 0; j < w; j++)
            e[min(f[i][j], f[i + 1][j])].push_back({i * w + j, (i + 1) * w + j});
    // 添加水平方向的边
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w - 1; j++)
            e[min(f[i][j], f[i][j + 1])].push_back({i * w + j, i * w + (j + 1)});
    // 初始化二分查找的边界
    for (int i = 0; i < q; i++)
        l[i] = 1, r[i] = F + 1;

    // 二分查找过程
    while (true)
    {
        bool flag = true;
        // 清空check数组
        for (int i = 0; i <= F; i++)
            check[i].clear();
        // 对每个查询,如果二分区间未收敛,则加入check数组
        for (int i = 0; i < q; i++)
        {
            if (r[i] - l[i] > 1)
            {
                check[(l[i] + r[i]) / 2].push_back(i);
                flag = false;
            }
        }
        if (flag) break;  // 如果所有查询都已收敛,退出循环

        // 使用并查集检查连通性
        dsu uf(h * w);
        // 从大到小遍历权值
        for (int i = F; i >= 0; i--)
        {
            // 合并权值为i的所有边
            int sz = e[i].size();
            for (int j = 0; j < sz; j++)
                uf.merge(e[i][j].first, e[i][j].second);
            // 检查需要在权值i处判断的查询
            sz = check[i].size();
            for (int j = 0; j < sz; j++)
            {
                int idx_s = a[check[i][j]] * w + b[check[i][j]];  // 起点在一维数组中的索引
                int idx_t = c[check[i][j]] * w + d[check[i][j]];  // 终点在一维数组中的索引
                // 根据连通性更新二分边界
                if (uf.same(idx_s, idx_t))
                    l[check[i][j]] = i;
                else
                    r[check[i][j]] = i;
            }
        }
    }

    // 输出每个查询的结果
    for (int i = 0; i < q; i++)
        cout << (y[i] + z[i] - 2 * min(l[i], min(y[i], z[i]))) << endl;
    return 0;
}
