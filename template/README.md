# 算法竞赛模板库

这是一个为算法竞赛准备的 C++ 模板库，包含了常见的数据结构和算法实现。

## 📁 目录结构

```
template/
├── data-structures/     # 数据结构
├── graphs/             # 图算法
├── math/               # 数学算法
├── searching/          # 搜索算法
├── dynamic_programming/ # 动态规划
├── strings/            # 字符串算法
└── README.md           # 本文件
```

## 📚 内容索引

### 数据结构 (data-structures/)

| 文件 | 内容 | 时间复杂度 |
|------|------|-----------|
| [segment_tree.cpp](data-structures/segment_tree.cpp) | 线段树（区间查询与修改） | 查询/修改: O(log n) |
| [fenwick_tree.cpp](data-structures/fenwick_tree.cpp) | 树状数组（前缀和） | 查询/修改: O(log n) |
| [union_find.cpp](data-structures/union_find.cpp) | 并查集（动态连通性） | find/union: O(α(n)) |
| [sparse_table.cpp](data-structures/sparse_table.cpp) | 稀疏表（RMQ问题） | 预处理: O(n log n), 查询: O(1) |
| [trie.cpp](data-structures/trie.cpp) | 字典树（字符串检索） | 插入/查询: O(L) |

### 图算法 (graphs/)

| 文件 | 内容 | 时间复杂度 |
|------|------|-----------|
| [dfs.cpp](graphs/dfs.cpp) | 深度优先搜索 | O(V + E) |
| [bfs.cpp](graphs/bfs.cpp) | 广度优先搜索 | O(V + E) |
| [dijkstra.cpp](graphs/dijkstra.cpp) | Dijkstra最短路径 | O((V + E) log V) |
| [bellman_ford.cpp](graphs/bellman_ford.cpp) | Bellman-Ford最短路径 | O(VE) |
| [floyd_warshall.cpp](graphs/floyd_warshall.cpp) | Floyd-Warshall全源最短路径 | O(V³) |
| [topological_sort.cpp](graphs/topological_sort.cpp) | 拓扑排序 | O(V + E) |
| [strongly_connected_components.cpp](graphs/strongly_connected_components.cpp) | 强连通分量 | O(V + E) |
| [kruskal.cpp](graphs/kruskal.cpp) | Kruskal最小生成树 | O(E log E) |

### 数学算法 (math/)

| 文件 | 内容 | 时间复杂度 |
|------|------|-----------|
| [prime_sieve.cpp](math/prime_sieve.cpp) | 埃拉托斯特尼筛法（素数筛） | O(n log log n) |
| [gcd_lcm.cpp](math/gcd_lcm.cpp) | 最大公约数与最小公倍数 | O(log min(a,b)) |
| [extended_euclidean.cpp](math/extended_euclidean.cpp) | 扩展欧几里得算法 | O(log min(a,b)) |
| [matrix_exponentiation.cpp](math/matrix_exponentiation.cpp) | 矩阵快速幂 | O(n³ log k) |
| [nCr_mod.cpp](math/nCr_mod.cpp) | 组合数取模 | 预处理: O(n), 查询: O(1) |
| [modular_inverse.cpp](math/modular_inverse.cpp) | 模逆元 | O(log m) |

### 搜索算法 (searching/)

| 文件 | 内容 | 时间复杂度 |
|------|------|-----------|
| [binary_search.cpp](searching/binary_search.cpp) | 二分查找 | O(log n) |
| [ternary_search.cpp](searching/ternary_search.cpp) | 三分查找 | O(log n) |
| [lower_upper_bound.cpp](searching/lower_upper_bound.cpp) | 边界查找 | O(log n) |
| [interpolation_search.cpp](searching/interpolation_search.cpp) | 插值查找 | 平均: O(log log n) |

### 动态规划 (dynamic_programming/)

| 文件 | 内容 | 时间复杂度 |
|------|------|-----------|
| [knapsack.cpp](dynamic_programming/knapsack.cpp) | 背包问题合集 | O(nW) |
| [longest_common_subsequence.cpp](dynamic_programming/longest_common_subsequence.cpp) | 最长公共子序列 | O(mn) |
| [longest_increasing_subsequence.cpp](dynamic_programming/longest_increasing_subsequence.cpp) | 最长递增子序列 | O(n log n) |
| [matrix_chain_multiplication.cpp](dynamic_programming/matrix_chain_multiplication.cpp) | 矩阵链乘法 | O(n³) |
| [coin_change.cpp](dynamic_programming/coin_change.cpp) | 零钱兑换 | O(amount × n) |

### 字符串算法 (strings/)

| 文件 | 内容 | 时间复杂度 |
|------|------|-----------|
| [knuth_morris_pratt.cpp](strings/knuth_morris_pratt.cpp) | KMP字符串匹配 | O(n + m) |
| [z_algorithm.cpp](strings/z_algorithm.cpp) | Z算法 | O(n) |
| [suffix_array.cpp](strings/suffix_array.cpp) | 后缀数组 | O(n log n) |
| [rabin_karp.cpp](strings/rabin_karp.cpp) | Rabin-Karp算法 | 平均: O(n + m) |
| [string_hashing.cpp](strings/string_hashing.cpp) | 字符串哈希 | 预处理: O(n), 查询: O(1) |

## 🚀 使用方法

1. **直接复制**：将需要的模板代码复制到你的解题代码中
2. **学习参考**：每个文件都包含详细的注释和使用示例
3. **修改适配**：根据具体题目要求调整模板代码

### 使用示例

```cpp
#include <bits/stdc++.h>
using namespace std;

// 复制你需要的模板代码
class UnionFind {
    // ... 模板代码 ...
};

int main() {
    // 使用模板解题
    UnionFind uf(100);
    uf.unite(1, 2);
    cout << uf.connected(1, 2) << endl;

    return 0;
}
```

## 📝 代码规范

- 所有模板使用 C++11 及以上标准
- 采用算法竞赛常用的编码风格
- 每个文件包含：
  - 算法说明和用途
  - 时间/空间复杂度分析
  - 完整的实现代码
  - 使用示例

## 🎯 适用场景

- **算法竞赛**：ACM-ICPC、Codeforces、AtCoder等
- **在线评测**：LeetCode、洛谷、牛客网等
- **学习练习**：算法学习和面试准备

## ⚠️ 注意事项

1. **MOD值**：某些模板使用 `1e9+7` 作为模数，根据题目要求修改
2. **数据范围**：注意整型溢出，必要时使用 `long long`
3. **输入输出**：模板仅提供核心算法，需自行处理输入输出
4. **测试验证**：使用前请在样例上测试验证

## 📖 学习资源

- [OI Wiki](https://oi-wiki.org/)
- [CP-Algorithms](https://cp-algorithms.com/)
- [Codeforces](https://codeforces.com/)
- [LeetCode](https://leetcode.com/)

## 🔄 更新日志

- 2025-12-11: 初始版本，包含基础数据结构和算法模板

## 📧 反馈建议

如有问题或建议，欢迎提出 Issue 或 Pull Request。

---

**Happy Coding! 祝你在算法竞赛中取得好成绩！** 🎉
