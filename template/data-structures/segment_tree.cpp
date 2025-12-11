/*
 * 线段树 (Segment Tree)
 * 用途：区间查询和修改（如区间求和、区间最值等）
 * 时间复杂度：建树 O(n)，查询/修改 O(log n)
 * 空间复杂度：O(4n)
 */

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree, lazy;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    void updateRange(int node, int start, int end, int l, int r, long long val) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2*node] += val;
                lazy[2*node+1] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2*node, start, mid, l, r, val);
        updateRange(2*node+1, mid+1, end, l, r, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l) return 0;

        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        long long p1 = queryRange(2*node, start, mid, l, r);
        long long p2 = queryRange(2*node+1, mid+1, end, l, r);
        return p1 + p2;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(arr, 1, 0, n-1);
    }

    void update(int l, int r, long long val) {
        updateRange(1, 0, n-1, l, r, val);
    }

    long long query(int l, int r) {
        return queryRange(1, 0, n-1, l, r);
    }
};

// 使用示例
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << st.query(1, 3) << endl;  // 输出: 15 (3+5+7)
    st.update(1, 3, 10);              // 区间[1,3]每个元素加10
    cout << st.query(1, 3) << endl;  // 输出: 45 (13+15+17)

    return 0;
}
