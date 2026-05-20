/*
 * @acwing app=acwing.cn id=61 lang=C++
 *
 * 65. 数组中的逆序对
 */

// @acwing code start

class Solution {
   public:
    vector<int> nums;
    int res = 0;

    int merge(int l, int r) {
        if (l >= r)
            return 0;
        int mid = (l + r) >> 1;
        int i = l, j = mid + 1;

        int sum = merge(l, mid) + merge(mid + 1, r);

        vector<int> temp;
        temp.reserve(r - l + 1);
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
                sum += mid - i + 1;
            }
        }

        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= r)
            temp.push_back(nums[j++]);

        i = l;
        for (auto x : temp) {
            nums[i++] = x;
        }
        return sum;
    }

    int inversePairs(vector<int> &_nums) {
        nums = _nums;
        int res = merge(0, nums.size() - 1);
        return res;
    }
};
// @acwing code end
