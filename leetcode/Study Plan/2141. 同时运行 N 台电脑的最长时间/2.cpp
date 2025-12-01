class Solution {
    public:
        long long maxRunTime(int n, vector<int>& batteries) {
            ranges::sort(batteries,greater<int>());
            long long sum = reduce(batteries.begin(),batteries.end(),0LL);
            for(int i =0; ;++i)
            {
                if(batteries[i] <= sum / n)
                {
                    return sum / n;
                }
                sum -= batteries[i];
                --n;
            }
        }
    };
