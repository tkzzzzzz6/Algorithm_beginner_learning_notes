#include <bits/stdc++.h>
#define il inline
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0); // 加速输入输出

typedef long long ll;
typedef unsigned long long ull;
typedef long double db;

// 常量定义
const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

// 快速幂函数：计算 a^b % m，默认b=mod-2用于求逆元
ll fast_pow(ll a, ll b = mod - 2, ll m = mod)
{
    a %= m;
    ll ans = 1;
    while (b)
    {
        if (b & 1) // 如果b的当前位为1
        {
            ans = ans * a % m;
        }
        a = (a * a) % m; // a = a^2
        b >>= 1;         // b右移一位
    }
    return ans;
}

// 并查集（Disjoint Set Union）类
class DSU
{
private:
    vector<ll> parent; // 父节点数组
    vector<ll> rank;   // 秩（树的深度）
    vector<ll> size;   // 集合大小
public:
    // 构造函数：初始化n个独立的集合
    DSU(ll n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);
        for (ll i = 0; i < n; ++i)
        {
            parent[i] = i; // 初始时每个节点的父节点是自己
        }
    }
    // 查找函数：找到p所在集合的根节点，并进行路径压缩
    ll find(ll p)
    {
        if (parent[p] != p)
            parent[p] = find(parent[p]); // 路径压缩
        return parent[p];
    }

    // 合并函数：将p和q所在的集合合并，按秩合并
    void unite(ll p, ll q)
    {
        ll rootp = find(p);
        ll rootq = find(q);
        if (rootp == rootq) // 已在同一集合
            return;
        // 按秩合并：将深度小的树连接到深度大的树上
        if (rank[rootp] > rank[rootq])
        {
            parent[rootq] = rootp;
            size[rootp] += size[rootq];
        }
        else if (rank[rootp] < rank[rootq])
        {
            parent[rootp] = rootq;
            size[rootq] += size[rootp];
        }
        else
        {
            parent[rootq] = rootp;
            size[rootp] += size[rootq];
            rank[rootp]++;
        }
    }

    // 判断x和y是否在同一个集合中
    bool connected(ll x, ll y)
    {
        return find(x) == find(y);
    }

    // 获取p所在集合的大小
    ll getSize(ll p)
    {
        return size[find(p)];
    }

    // 统计集合数量
    ll count()
    {
        ll ans = 0;
        for (ll i = 0; i < parent.size(); ++i)
        {
            ans += (parent[i] == i); // 根节点的父节点是自己
        }
        return ans;
    }
};

// 主求解函数
il void solve()
{
    ll n, m, c;
    cin >> n >> m >> c; // n个节点，m条边，预算c

    // 存储所有边：{起点, 终点, 权值}
    vector<array<ll, 3>> egs(m);
    for (ll i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        egs[i] = {u, v, w};
    }

    // 按边权值从小到大排序（Kruskal算法）
    sort(egs.begin(), egs.end(), [](auto &a, auto &b)
         { return a[2] < b[2]; });

    // 使用并查集构建最小生成树
    DSU dsu(n);
    vector<ll> use; // 记录最小生成树中使用的边权值
    for (auto [u, v, w] : egs)
    {
        if (!dsu.connected(u, v)) // 如果u和v不在同一连通分量
        {
            use.pb(w);       // 使用这条边
            dsu.unite(u, v); // 合并两个连通分量
        }
    }

    // 将边权值从大到小排列
    reverse(use.begin(), use.end());

    // 计算累计成本，找到第一个超过预算的边
    ll tot = 0;
    for (ll i = 0; i <= use.size(); ++i)
    {
        tot += use[i - 1] * i; // 累加成本
        if (tot > c)           // 如果超过预算
        {
            cout << use[i - 1] << endl; // 输出导致超预算的边权值
            return;
        }
    }
    cout << 0 << endl; // 所有边都在预算内
}

// 主函数
int main()
{
    fastio; // 加速输入输出

    int t = 1; // 测试用例数量
    // cin >> t;  // 如果有多组测试数据，取消此行注释
    while (t--)
    {
        solve(); // 处理每组测试数据
    }

    return 0;
}