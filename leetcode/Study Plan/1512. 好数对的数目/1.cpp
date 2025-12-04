class Solution {
    public:
        int numIdenticalPairs(vector<int>& nums) {
            map<int,int> cnt;
            for(int num : nums)
            {
                cnt[num]++;
            }
            int ans = 0;
            for(auto [num,count] : cnt)
            {
                if(count > 1)
                {
                    ans += count * (count-1) / 2;
                }
            }
            return ans;
        }
    };
