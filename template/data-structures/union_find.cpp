/*
 * 并查集 (Union-Find / Disjoint Set Union - DSU)
 * 用途：处理动态连通性问题、判断图中的连通分量
 * 时间复杂度：find/union 均摊 O(α(n))，α(n) 为阿克曼函数的反函数，可视为常数
 * 空间复杂度：O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;  // 每个集合的大小
    int count;         // 连通分量个数

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        count = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // 查找根节点（带路径压缩）
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 路径压缩
        }
        return parent[x];
    }

    // 合并两个集合（按秩合并）
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;  // 已经在同一集合中

        // 按秩合并
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            rank[rootX]++;
        }
        count--;
        return true;
    }

    // 判断两个元素是否在同一集合中
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    // 获取连通分量个数
    int getCount() {
        return count;
    }

    // 获取某个元素所在集合的大小
    int getSize(int x) {
        return size[find(x)];
    }
};

// 使用示例
int main() {
    int n = 7;
    UnionFind uf(n);

    uf.unite(0, 1);
    uf.unite(1, 2);
    uf.unite(3, 4);

    cout << uf.connected(0, 2) << endl;  // 输出: 1 (true)
    cout << uf.connected(0, 3) << endl;  // 输出: 0 (false)
    cout << uf.getCount() << endl;       // 输出: 4 (4个连通分量)
    cout << uf.getSize(0) << endl;       // 输出: 3 ({0,1,2})

    uf.unite(2, 3);
    cout << uf.connected(0, 4) << endl;  // 输出: 1 (true)
    cout << uf.getCount() << endl;       // 输出: 3

    return 0;
}
