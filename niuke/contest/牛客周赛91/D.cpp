#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 定义最大数组大小
const int N = 200005;
// 并查集父节点数组
int parent[N];

// 并查集查找函数，带路径压缩
int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// 并查集合并函数
void unite(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        parent[fy] = fx;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        // 存储输入数组，下标从1开始
        vector<int> a(n + 1);
        // 使用哈希表记录每个值对应的所有位置
        unordered_map<int, vector<int>> mp;

        // 初始化并查集，同时记录每个值的位置
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            mp[a[i]].push_back(i);
            parent[i] = i;
        }

        // 处理相邻数字之间的边
        // 对于每个值，如果存在比它大1的值，则将它们的位置合并
        for (auto &[val, indices] : mp)
        {
            if (mp.count(val + 1))
            {
                for (int i : indices)
                {
                    for (int j : mp[val + 1])
                    {
                        unite(i, j);
                    }
                }
            }
        }

        // 统计连通块数量
        // 遍历所有节点，统计根节点数量即为连通块数量
        int components = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (find(i) == i)
            {
                components++;
            }
        }

        // 需要添加的边数 = 连通块数量 - 1
        // 因为要将所有连通块连接起来，需要连通块数量-1条边
        cout << components - 1 << endl;
    }
    return 0;
}