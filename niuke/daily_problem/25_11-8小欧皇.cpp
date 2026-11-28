#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <set>
#include <algorithm>

using namespace std;

// 并查集结构体：用于维护已占领城市各连通分量
struct DSU
{
    vector<int> parent;          // 父节点
    vector<long long> occupied_size; // 各连通分量已占领城市数量

    // 构造函数，n为城市数，s表示各城市占领情况
    DSU(int n, const string &s)
    {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // 初始每个点自成一集
        occupied_size.assign(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '1')
            {
                occupied_size[i + 1] = 1; // 已占领，size记为1
            }
        }
    }

    // 查找并查集根
    int find(int i)
    {
        if (parent[i] == i)
            return i;
        // 路径压缩
        return parent[i] = find(parent[i]);
    }

    // 合并城市i和j所在的连通分量
    void unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
        {
            // 将编号小的作为根
            if (root_i > root_j)
                swap(root_i, root_j);
            parent[root_j] = root_i;
            occupied_size[root_i] += occupied_size[root_j]; // size合并
        }
    }
};

// 计算组合数C(k,2)，即k个点能组成的配对数，代表收益
long long calculate_profit(long long k)
{
    if (k < 2)
        return 0;
    return k * (k - 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; // n个城市，m条边
    cin >> n >> m;
    string s;
    cin >> s; // 城市状态字符串（'1'为占领，'0'为未占领）
    vector<vector<int>> adj(n + 1); // 邻接表，1~n编号
    vector<pair<int, int>> edges;   // 存所有边

    // 读入边信息
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    // 1. 初始化并查集，处理初始状态下所有已占领城市所在的连通分量
    DSU dsu(n, s);
    for (const auto &edge : edges)
    {
        // 只有相连的两个城市都被占领时，才合并
        if (s[edge.first - 1] == '1' && s[edge.second - 1] == '1')
        {
            dsu.unite(edge.first, edge.second);
        }
    }

    // 2. 计算初始总收益：所有已占领连通分量，C(size, 2)求和
    long long initial_profit = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (dsu.parent[i] == i)
        {
            initial_profit += calculate_profit(dsu.occupied_size[i]);
        }
    }

    long long max_profit = -1; // 最大收益
    int best_city = -1;        // 对应城市编号

    // 3. 枚举所有未占领的城市，尝试占领它，计算新收益
    bool has_unoccupied = false;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i - 1] == '0') // 未占领
        {
            has_unoccupied = true;

            // 找出与城市i相邻且已占领的连通分量(根)，避免重复
            set<int> neighbor_roots;
            for (int neighbor : adj[i])
            {
                if (s[neighbor - 1] == '1')
                {
                    neighbor_roots.insert(dsu.find(neighbor));
                }
            }

            // 占领i后，相关分量合并 + i本身，需先移除各分量旧收益
            long long profit_to_remove = 0;
            long long new_component_size = 1; // i本身

            for (int root : neighbor_roots)
            {
                long long sz = dsu.occupied_size[root];
                profit_to_remove += calculate_profit(sz);
                new_component_size += sz; // 合并后的新size
            }

            // 新增合并的大连通分量收益
            long long profit_to_add = calculate_profit(new_component_size);
            // 当前总收益 = 初始-被合并分量旧收益+新大分量收益
            long long current_total_profit = initial_profit - profit_to_remove + profit_to_add;

            // 更新最大收益和对应城市
            if (best_city == -1 || current_total_profit > max_profit)
            {
                max_profit = current_total_profit;
                best_city = i;
            }
        }
    }

    // 若无未占领城市，输出-1和初始收益。题目保证一定有未占领点。
    if (!has_unoccupied)
    {
        cout << "-1 " << initial_profit << endl;
    }
    else
    {
        cout << best_city << " " << max_profit << endl;
    }

    return 0;
}
