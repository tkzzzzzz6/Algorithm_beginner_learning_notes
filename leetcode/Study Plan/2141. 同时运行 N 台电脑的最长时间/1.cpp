class Solution {
    public:
        long long maxRunTime(int n, vector<int>& batteries) {
            // 计算所有电池的总容量
            long long tot = reduce(batteries.begin(),batteries.end(),0LL);
            
            // 二分查找的左右边界
            // 理论上最多能运行 tot/n 分钟（平均分配），所以上界设为 tot/n+1
            long long l = 0, r = tot / n + 1;
            
            // 二分查找：找到最大的运行时间 x，使得 n 台电脑可以同时运行 x 分钟
            // 使用左闭右开区间 [l, r)
            while(l + 1 < r)
            {
                // 候选的运行时间
                long long x = l + (r - l) / 2;
                
                // 计算所有电池能提供的总能量
                // 对于每个电池，最多只能给一台电脑供电 x 分钟
                // 所以每个电池最多贡献 min(b, x) 的能量
                long long sum = 0;
                for(long long b : batteries)
                {
                    sum += min(b, x);
                }
                
                // 判断：如果总能量 sum >= n * x，说明可以让 n 台电脑运行 x 分钟
                // 此时可以尝试更大的 x（更新左边界）
                // 否则需要减小 x（更新右边界）
                (n * x <= sum ? l : r) = x;
            }
            
            // 返回最大的满足条件的运行时间
            return l;
        }
    };
