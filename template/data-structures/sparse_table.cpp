/*
 * 稀疏表 (Sparse Table)
 * 用途：RMQ问题（区间最值查询）、不可修改的区间查询
 * 时间复杂度：预处理 O(n log n)，查询 O(1)
 * 空间复杂度：O(n log n)
 * 注意：只适用于可重复贡献问题（如max, min, gcd），不适用于sum
 */

#include <bits/stdc++.h>
using namespace std;

class SparseTable {
private:
    vector<vector<int>> st;
    vector<int> log;
    int n;

public:
    SparseTable(vector<int>& arr) {
        n = arr.size();
        int maxLog = 32 - __builtin_clz(n);  // log2(n) + 1
        st.assign(n, vector<int>(maxLog));
        log.assign(n + 1, 0);

        // 预处理log值
        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }

        // 初始化st[i][0] = arr[i]
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }

        // 动态规划填表
        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    // 查询区间 [l, r] 的最小值
    int queryMin(int l, int r) {
        int len = r - l + 1;
        int k = log[len];
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

// 最大值版本的稀疏表
class SparseTableMax {
private:
    vector<vector<int>> st;
    vector<int> log;
    int n;

public:
    SparseTableMax(vector<int>& arr) {
        n = arr.size();
        int maxLog = 32 - __builtin_clz(n);
        st.assign(n, vector<int>(maxLog));
        log.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }

        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    // 查询区间 [l, r] 的最大值
    int queryMax(int l, int r) {
        int len = r - l + 1;
        int k = log[len];
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

// 使用示例
int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    SparseTable st(arr);
    SparseTableMax stMax(arr);

    cout << st.queryMin(2, 5) << endl;     // 输出: 1 (区间[2,5]的最小值)
    cout << stMax.queryMax(2, 5) << endl;  // 输出: 9 (区间[2,5]的最大值)
    cout << st.queryMin(0, 7) << endl;     // 输出: 1 (整个数组的最小值)

    return 0;
}
