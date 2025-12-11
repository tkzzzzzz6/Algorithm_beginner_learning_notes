class Solution {
   public:
    int specialTriplets(vector<int> &nums) {
        const int mod = 1e9+7;
        unordered_map<int,int>suf;
        for(int x:nums)
        {
            suf[x]++;
        }
        unordered_map<int,int>pre;
        long long ans = 0;
        for(int x:nums)
        {
            suf[x]--;
            ans+=1LL*pre[x*2]*suf[x*2];
            pre[x]++;
        }
        return ans%mod;
    }
};
