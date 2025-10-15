#include <bits/c++.h>

// 滑动窗口

class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        // 用于统计每个二进制位上1的个数,bits[i]表示第i位上1的个数
        vector<int> bits(30);

        // 计算当前窗口内所有数字按位或的结果
        auto calc = [](vector<int> &bits) -> int
        {
            int ans = 0;
            for (int i = 0; i < bits.size(); i++)
            {
                // 如果第i位上有1,则将结果的第i位置为1
                if (bits[i] > 0)
                {
                    ans |= 1 << i;
                }
            }
            return ans;
        };

        // 记录最小子数组长度
        int res = INT_MAX;
        // 滑动窗口,left为左边界,right为右边界
        for (int left = 0, right = 0; right < n; right++)
        {
            // 将右边界的数加入窗口,更新每个二进制位上1的个数
            for (int i = 0; i < 30; i++)
            {
                bits[i] += (nums[right] >> i) & 1;
            }
            // 当窗口内的数按位或结果大于等于k时,尝试缩小窗口
            while (left <= right && calc(bits) >= k)
            {
                // 更新最小长度
                res = min(res, right - left + 1);
                // 将左边界的数移出窗口,更新每个二进制位上1的个数
                for (int i = 0; i < 30; i++)
                {
                    bits[i] -= (nums[left] >> i) & 1;
                }
                left++;
            }
        }

        // 如果没有找到满足条件的子数组,返回-1
        return res == INT_MAX ? -1 : res;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {2, 1, 8};
    int k = 10;

    int result = solution.minimumSubarrayLength(nums, k);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
