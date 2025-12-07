#include<vector>
#include<set>
using namespace std;
class Solution{
    public:
    int countPartitions(vector<int>& nums,int k){
        int n = nums.size();
        long long mod = 1e9+7;
        vector<long long> dp(n+1);
        vector<long long> prefix(n+1);
        multiset<int> cnt;
        dp[0] = 1;
        prefix[0] = 1;
        for(int i = 0,j = 0;i<n;++i)
        {
            cnt.emplace(nums[i]);
            while(j <= i && *cnt.rbegin() - *cnt.begin() > k)
            {
                cnt.erase(cnt.find(nums[j]));
                ++j;
            }
            dp[i+1] = (prefix[i] - (j>0?prefix[j-1]:0) + mod)%mod;
            prefix[i+1] = (prefix[i] + dp[i+1])%mod;
        }
        return dp[n];
    }
};
