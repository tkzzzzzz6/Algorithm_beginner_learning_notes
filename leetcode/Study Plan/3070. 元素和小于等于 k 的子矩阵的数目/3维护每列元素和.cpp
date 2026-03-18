// 维护每列元素和
#include <vector>

using namespace std;

class Solution {
public:
  int countSubmatrices(vector<vector<int>> &grid, int k) {
    int n = grid[0].size();
    vector<int> col_sum(n);
    int ans = 0;
    for(auto &row:grid){
        int s = 0;
        for(int j = 0;j<n;++j){
            col_sum[j] += row[j];
            s += col_sum[j];
            if(s > k)break;
            ++ans;
        }
    }
    return ans;
  }
};
