class Solution {
    public:
        int countPartitions(vector<int>& nums) {
            int sum = reduce(nums.begin(),nums.end());
            return sum % 2 ? 0 : nums.size() - 1;
        }
    };
