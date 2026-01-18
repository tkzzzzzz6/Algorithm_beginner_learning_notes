#include <cmath>
#include <vector>
using namespace std;

class Solution {
   public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
        int res = 0;
        if(points.size() == 0)return 0;
        auto& p = points[0];
        for (int i = 1; i < points.size(); ++i) {
            auto &q = points[i];
            res += max(abs(p[0] - q[0]), abs(p[1] - q[1])); // 切比雪夫距离
            p = q;
        }
        return res;
    }
};
