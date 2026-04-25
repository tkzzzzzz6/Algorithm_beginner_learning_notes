#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        // right使用accumulate函数计算整个数组的和
        // accumulate(开始迭代器, 结束迭代器, 初始值)
        // 0LL表示long long类型的0,防止整数溢出
        long long left = 0, right = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            left += nums[i];
            right -= nums[i];
            if (left >= right)
            {
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 4, -8, 7};
    cout << s.waysToSplitArray(nums) << endl;
    return 0;
}
