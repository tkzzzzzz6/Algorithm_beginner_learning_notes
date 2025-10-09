class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (1)
        {
            int s = numbers[left] + numbers[right];
            if (s == target)
                break;
            if (s > target)
                --right;
            else
                ++left;
        }
        return {left + 1, right + 1};
    }
};