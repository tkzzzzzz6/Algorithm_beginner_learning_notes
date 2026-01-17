class SegmentTree {
   private:
    vector<int> count;
    vector<int> covered;
    vector<int> xs;
    int n;

    void modify(int qleft, int qright, int qval, int left, int right, int pos) {
        if (xs[right + 1] <= qleft || xs[left] >= qright) {
            return;
        }
        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        } else {
            int mid = (left + right) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (count[pos] > 0) {
            covered[pos] = xs[right + 1] - xs[left];
        } else {
            if (left == right) {
                covered[pos] = 0;
            } else {
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

   public:
    SegmentTree(vector<int> &xs_) : xs(xs_) {
        n = xs.size() - 1;
        count.resize(4 * n, 0);
        covered.resize(4 * n, 0);
    }

    void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n - 1, 0);
    }

    int query() {
        return covered[0];
    }
};

class Solution {
   public:
    double separateSquares(vector<vector<int>> &squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> xsSet;

        for (auto &sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.emplace_back(y, 1, x, xr);
            events.emplace_back(y + l, -1, x, xr);
            xsSet.insert(x);
            xsSet.insert(xr);
        }

        // 按y坐标排序事件
        sort(events.begin(), events.end());
        // 离散化坐标
        vector<int> xs(xsSet.begin(), xsSet.end());
        // 初始化线段树
        SegmentTree segTree(xs);

        vector<double> psum;
        vector<int> widths;
        double total_area = 0.0;
        int prev = get<0>(events[0]);

        // 扫描：计算总面积和记录中间状态
        for (auto &[y, delta, xl, xr] : events) {
            int len = segTree.query();
            total_area += 1LL * len * (y - prev);
            segTree.update(xl, xr, delta);
            // 记录前缀和和宽度
            psum.push_back(total_area);
            widths.push_back(segTree.query());
            prev = y;
        }

        // 计算目标面积（向上取整的一半）
        long long target = (long long)(total_area + 1) / 2;
        // 二分查找第一个大于等于target的位置
        int i = lower_bound(psum.begin(), psum.end(), target) - psum.begin() - 1;
        // 获取对应的面积、宽度和高度
        double area = psum[i];
        int width = widths[i], height = get<0>(events[i]);

        return height + (total_area - area * 2) / (width * 2.0);
    }
};
