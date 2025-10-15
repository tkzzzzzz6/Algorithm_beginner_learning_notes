class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        while (left < nums.size() && nums[left] < target)
            left++;
        if (left == nums.size() || nums[left] != target)
            return {-1, -1};
        int right = left;
        while (right < nums.size() && nums[right] == target)
            right++;
        return {left, right - 1};
    }
};