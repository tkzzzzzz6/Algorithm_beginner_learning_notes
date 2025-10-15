#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        int n = nums.size();

        // 如果 k 大于数组大小，则不存在有效的子数组
        if (k > n)
            return -1;

        // 统计每个 k 大小子数组中每个数字的出现次数
        unordered_map<int, int> subArrayCount;

        // 对于每个可能的 k 大小子数组的起始位置
        for (int i = 0; i <= n - k; i++)
        {
            // 创建一个集合来跟踪此子数组中的唯一数字
            unordered_map<int, bool> seen;

            // 处理当前子数组中的每个元素
            for (int j = i; j < i + k; j++)
            {
                int num = nums[j];

                // 如果这是我们第一次在此子数组中看到这个数字
                if (!seen[num])
                {
                    seen[num] = true;
                    subArrayCount[num]++;
                }
            }
        }

        // 找到仅在一个子数组中出现的最大数字
        int result = -1;
        for (auto &[num, count] : subArrayCount)
        {
            if (count == 1 && num > result)
            {
                result = num;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;

    // Example 1
    vector<int> nums1 = {3, 9, 2, 1, 7};
    int k1 = 3;
    cout << "Example 1: " << s.largestInteger(nums1, k1) << endl; // Expected: 7

    // Example 2
    vector<int> nums2 = {3, 9, 7, 2, 1, 7};
    int k2 = 4;
    cout << "Example 2: " << s.largestInteger(nums2, k2) << endl; // Expected: 3

    // Example 3
    vector<int> nums3 = {0, 0};
    int k3 = 1;
    cout << "Example 3: " << s.largestInteger(nums3, k3) << endl; // Expected: -1

    return 0;
}
