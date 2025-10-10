class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size();
        int mid = 0;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid;
            if (nums[mid] < target)
                left = mid + 1;
            if (nums[mid] == target)
                return mid;
        }
        return left;
    }
};