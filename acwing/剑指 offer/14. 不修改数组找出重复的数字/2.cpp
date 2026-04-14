/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-14 08:24:21
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-14 08:55:00
 */
/*
* @acwing app=acwing.cn id=15 lang=C++
*
* 14. 不修改数组找出重复的数字
*/

// @acwing code start

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int l = 1,r = nums.size()-1;
        while(l < r){
            int mid = l + ((r - l) >> 1);
            int cnt = 0;
            for(auto x:nums)cnt+=x >= l && x <= mid;
            if(cnt > mid - l + 1)r = mid; //多的数在左边
            else l = mid + 1;
        }
        return l;
    }
};
// @acwing code end

