class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0, right = 0;
        int curr_or = 0;
        int min_len = n + 1;

        while (right < n)
        {
            curr_or |= nums[right];

            // 当找到一个满足条件的窗口时
            while (curr_or >= k)
            {
                min_len = min(min_len, right - left + 1);

                // 重新计算从left+1到right的或值
                int new_or = 0;
                for (int i = left + 1; i <= right; i++)
                {
                    new_or |= nums[i];
                }

                // 如果移除left后仍然满足条件，继续收缩
                if (new_or >= k)
                {
                    curr_or = new_or;
                    left++;
                }
                else
                {
                    break;
                }
            }
            right++;
        }

        return min_len == n + 1 ? -1 : min_len;
    }
};