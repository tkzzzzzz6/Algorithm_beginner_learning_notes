#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    int longestConsecutive(std::vector<int> &nums) {
        // 1. 将所有元素存入哈希集合
        std::unordered_set<int> hmap(nums.begin(), nums.end());
        int ans = 0;

        // 获取不同元素的总个数 M
        int M = hmap.size();

        for (auto x : nums) {

            // 核心优化：只从连续序列的起点开始检查
            // 如果 x-1 存在，说明 x 不是起点，跳过
            if (hmap.count(x - 1))
                continue;

            int length = 1;
            int y = x + 1;

            // 延伸序列
            while (hmap.count(y)) {
                length++;
                y++;
            }

            // 更新答案
            ans = std::max(ans, length);

            // 【额外的剪枝优化】: 检查当前找到的最长长度 ans
            // 如果 ans * 2 > M，那么后续找到更长的链的可能性极低（除非当前 ans 已经是最优解）
            // 注意：这里 M 是 hmap 的大小，也就是不同元素的个数。
            if (ans * 2 > M) {
                return ans;
            }
        }

        return ans;
    }
};
