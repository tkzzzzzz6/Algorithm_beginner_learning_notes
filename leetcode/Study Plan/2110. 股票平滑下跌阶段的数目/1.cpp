#include <vector>
using namespace std;
class Solution {
   public:
    long long getDescentPeriods(vector<int> &prices) {
        long long ans = 0;
        int n = prices.size();
        int dec = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && prices[i] == prices[i - 1] - 1) {
                ++dec;
            } else {
                dec = 1;
            }
            ans += dec;
        }
        return ans;
    }
};

