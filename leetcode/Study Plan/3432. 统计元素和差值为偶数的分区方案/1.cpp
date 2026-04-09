#include <vector>
#include <numeric>
class Solution {
    public:
        /**
         * @brief Compute a partition-count value determined by whether the sum of `nums` is odd or even.
         *
         * @param nums Input vector of integers whose elements are summed.
         * @return int `0` if the total sum of `nums` is odd; otherwise `nums.size() - 1` (which is `-1` for an empty vector).
         */
        int countPartitions(vector<int>& nums) {
            int sum = reduce(nums.begin(),nums.end());
            return sum % 2 ? 0 : nums.size() - 1;
        }
    };
