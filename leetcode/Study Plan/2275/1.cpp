class Solution
{
public:
    // 找出数组中按位与(&)运算结果不为0的最大子数组长度
    // 思路: 统计每一位上1的个数,最大的个数即为所求
    // 因为只要这些数在某一位上都为1,按位与的结果在该位上就为1,整体结果就不为0
    int largestCombination(vector<int> &candidates)
    {
        int result = 0;
        // 遍历32位(因为是int型整数)
        for (int bit = 0; bit < 32; bit++)
        {
            int count = 0;
            // 遍历数组中的每个数
            for (int num : candidates)
            {
                // num >> bit 将num右移bit位
                // & 1 判断最低位是否为1
                // 即判断num的第bit位是否为1
                if ((num >> bit) & 1)
                {
                    count++; // 统计当前位上1的个数
                }
            }
            // 更新最大值
            // 因为我们要找能使按位与不为0的最大子数组
            // 而在某位上为1的数的个数就是可能的子数组大小
            result = max(result, count);
        }
        return result; // 返回最大子数组长度
    }
};
