#include <algtorithm>
#include <climits>
#include <vector>
using namespace std;
class Solution {
   public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings) {
        vector<int> row_min(n + 1, INT_MAX), row_max(n + 1);
        vector<int> col_min(n + 1, INT_MAX), col_max(n + 1);
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            row_min[y] = min(row_min[y], x);
            row_max[y] = max(row_max[y], x);
            col_min[x] = min(col_min[x], y);
            col_max[x] = max(col_max[x], y);
        }
        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            if (row_min[y] < x && row_max[y] > x && col_min[x] < y && col_max[x] > y)
                ++ans;
        }
        return ans;
    }
};
