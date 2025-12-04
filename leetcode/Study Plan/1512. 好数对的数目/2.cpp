class Solution{
    public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int>cnt;
        for(int x:nums)
        {
            ans += cnt[x];
            cnt[x]++;
        }
        return ans;
    }
};
