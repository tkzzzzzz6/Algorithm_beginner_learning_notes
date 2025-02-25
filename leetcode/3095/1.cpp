#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int minimumSubarrayLength(std::vector<int> nums, int k)
    {
        int n = nums.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int value = 0;
            for (int j = i; j < n; j++)
            {
                value |= nums[j];
                if (value >= k)
                {
                    res = std::min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2, 1, 8};
    int k = 10;
    
    int result = solution.minimumSubarrayLength(nums, k);
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}
