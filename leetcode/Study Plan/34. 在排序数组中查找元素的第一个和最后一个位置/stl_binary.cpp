#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // 使用lower_bound找到第一个大于等于target的位置
        auto first = lower_bound(nums.begin(), nums.end(), target);

        // 如果没找到或者找到的值不等于target
        if (first == nums.end() || *first != target)
        {
            return {-1, -1};
        }

        // 使用upper_bound找到第一个大于target的位置
        auto last = upper_bound(nums.begin(), nums.end(), target);

        // 转换为索引
        int firstIndex = first - nums.begin();
        int lastIndex = (last - nums.begin()) - 1; // 减1是因为upper_bound返回的是第一个大于的位置

        return {firstIndex, lastIndex};
    }
};

// 测试函数
int main()
{
    Solution solution;

    // 测试用例1
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = solution.searchRange(nums1, target1);
    cout << "数组: [5,7,7,8,8,10], 目标: " << target1 << endl;
    cout << "结果: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // 测试用例2
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = solution.searchRange(nums2, target2);
    cout << "数组: [5,7,7,8,8,10], 目标: " << target2 << endl;
    cout << "结果: [" << result2[0] << ", " << result2[1] << "]" << endl;

    // 测试用例3
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int target3 = 1;
    vector<int> result3 = solution.searchRange(nums3, target3);
    cout << "数组: [1,1,1,1,1], 目标: " << target3 << endl;
    cout << "结果: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}