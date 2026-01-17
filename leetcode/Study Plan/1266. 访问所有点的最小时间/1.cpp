#include <cmath>
#include <vector>
using namespace std;

class Solution {
   public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
        int res = 0;
        for (int i = 1; i < points.size(); ++i) {
            auto &p = points[i - 1];
            auto &q = points[i];
            res += max(abs(p[0] - q[0]), abs(p[1] - q[1])); // 切比雪夫距离
        }
        return res;
    }
};
