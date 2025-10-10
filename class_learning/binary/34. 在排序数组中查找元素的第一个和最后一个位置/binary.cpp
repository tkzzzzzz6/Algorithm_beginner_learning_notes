class Solution
{
    int lower_bound(vector<int> &nums, int target)
    {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid - 1;
            if (nums[mid] < target)
                left = mid + 1;
        }
        return left;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
            return {-1, -1};
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};