class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        const int mod = 1e9+7;
        long long ans = 1;
        for(int j = 1;j<n;++j)
        {
            if(complexity[j] < complexity[0])
            {
                return 0;
            }
            ans = (1LL*ans*j)%mod;
        }
        return ans;
    }
};
