#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};

        // 先找到target的任意一个位置
        int left = 0, right = n - 1;
        int found = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                found = mid;
                break;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (found == -1)
            return {-1, -1};

        // 从找到的位置向两边扩展
        int first = found, last = found;

        // 向左找第一个位置
        while (first > 0 && nums[first - 1] == target)
        {
            first--;
        }

        // 向右找最后一个位置
        while (last < n - 1 && nums[last + 1] == target)
        {
            last++;
        }

        return {first, last};
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