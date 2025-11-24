class Solution {
    public:
        int maxSumDivThree(vector<int>& nums) {
            // 计算所有数字的总和
            int s = accumulate(nums.begin(), nums.end(), 0);
            
            // 如果总和已经能被3整除，直接返回
            if(s % 3 == 0) return s;

            // 按照模3的余数分组：a[0]存余数为0的，a[1]存余数为1的，a[2]存余数为2的
            vector<int> a[3];
            for(int num: nums) {
                a[num % 3].push_back(num);
            }
            
            // 对余数为1和2的数组排序，方便后续取最小值
            sort(a[1].begin(), a[1].end());
            sort(a[2].begin(), a[2].end());

            // 如果总和模3余2，交换a[1]和a[2]，统一处理为"需要移除余数为1的元素"
            // 这样后续逻辑只需要考虑移除1个或2个最小元素的情况
            if(s % 3 == 2) {
                swap(a[1], a[2]);
            }
            
            // 方案1：移除1个最小的余数为1的元素
            int ans = a[1].size() ? s - a[1][0] : 0;
            
            // 方案2：移除2个最小的余数为2的元素（因为2+2=4，4%3=1，相当于移除1）
            // 取两种方案的最大值
            if(a[2].size() > 1) {
                ans = max(ans, s - a[2][0] - a[2][1]);
            }
            
            return ans;
        }
    };
