/*
 * 树状数组 / Fenwick Tree / Binary Indexed Tree (BIT)
 * 用途：高效处理前缀和、单点修改、区间查询
 * 时间复杂度：查询/修改 O(log n)
 * 空间复杂度：O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    vector<long long> tree;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }

    FenwickTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            update(i, arr[i]);
        }
    }

    // 单点更新：给位置 idx 加上 delta
    void update(int idx, long long delta) {
        idx++; // 1-indexed
        while (idx <= n) {
            tree[idx] += delta;
            idx += idx & (-idx);
        }
    }

    // 查询前缀和 [0, idx]
    long long query(int idx) {
        idx++; // 1-indexed
        long long sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    // 查询区间和 [l, r]
    long long rangeQuery(int l, int r) {
        if (l > r) return 0;
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};

// 使用示例
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    FenwickTree ft(arr);

    cout << ft.query(2) << endl;        // 输出: 9 (1+3+5)
    cout << ft.rangeQuery(1, 3) << endl; // 输出: 15 (3+5+7)

    ft.update(2, 10);                    // arr[2] += 10
    cout << ft.rangeQuery(1, 3) << endl; // 输出: 25 (3+15+7)

    return 0;
}
