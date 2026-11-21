/*
 * @lc app=leetcode.cn id=2333 lang=cpp
 *
 * [2333] 最小差值平方和
 */

// @lc code=start
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        int max_d = 0;
        vector<int> cnt(100001,0);
        long long sum_d = 0;

        for(int i = 0;i<n;++i){
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            max_d = max(max_d,d);
            sum_d += d;
        }

        if(sum_d <= k)return 0;

        for(int v = max_d;v>0;--v){
            if(cnt[v] == 0)continue;

            if(k >= cnt[v]){
                k -= cnt[v];
                cnt[v - 1] += cnt[v];
                cnt[v] = 0;
            }else{
                cnt[v] -= k;
                cnt[v - 1] += k;
                k = 0;
                break;
            }
        }

        long long ans = 0;
        for(long long v = 1;v <= max_d;++v){
            if(cnt[v] > 0){
                ans += (long long)cnt[v] * v * v;
            }
        }

        return ans;
    }
};
// @lc code=end
