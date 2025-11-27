class Solution {
    public:
        long long maxSubarraySum(vector<int>& nums, int k) {
            vector<long long> min_s(k,LLONG_MAX/2);
            min_s.back() = 0;

            long long ans = LLONG_MIN;
            long long s = 0;
            for(int j = 0;j<nums.size();++j)
            {
                s+=nums[j];
                int i = j%k;
                ans = max(ans,s-min_s[i]);
                min_s[i] = min(min_s[i],s);
            }
            return ans;
        }
    };
