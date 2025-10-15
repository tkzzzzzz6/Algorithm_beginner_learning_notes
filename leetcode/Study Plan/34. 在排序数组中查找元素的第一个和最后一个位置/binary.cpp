#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 查找第一个等于target的位置
    int findFirst(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int result = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                result = mid;    // 记录当前位置
                right = mid - 1; // 继续在左半部分查找
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

        return result;
    }

    // 查找最后一个等于target的位置
    int findLast(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int result = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                result = mid;   // 记录当前位置
                left = mid + 1; // 继续在右半部分查找
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

        return result;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);

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
    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> result3 = solution.searchRange(nums3, target3);
    cout << "数组: [], 目标: " << target3 << endl;
    cout << "结果: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}