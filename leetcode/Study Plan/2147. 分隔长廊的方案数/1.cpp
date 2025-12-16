#include<string>
using namespace std;
class Solution {
public:
    int numberOfWays(string corridor) {
        constexpr int MOD = 1e9 + 7;
        long long  ans = 1;
        int cnt_s = 0,last_s = 0;

        for(int i = 0;i<corridor.size();++i)
        {
            if(corridor[i] == 'S')
            {
                ++cnt_s;
                // 对于3,5,7...个座位,可以在其到其左侧最近的座位之间的任意空隙放置屏风
                if(cnt_s >= 3 && cnt_s % 2 == 1)
                {
                    ans = (ans * (i - last_s)) % MOD;
                }
                last_s = i; //记录上一个座位的位置
            }
        }
        if(cnt_s == 0 || cnt_s % 2 == 1) //座位个数不能是0或者是奇数
        {
            return 0;
        }
        return ans;
    }
};
