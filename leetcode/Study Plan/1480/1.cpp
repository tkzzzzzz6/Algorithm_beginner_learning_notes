#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i-1];
        }
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2,3,4};
    vector<int> result = s.runningSum(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}