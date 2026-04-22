/*
#include <vector>
 * @Author: tkzzzzzz6
 * @Date: 2026-04-13 10:26:46
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-13 10:31:43
 */
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        unordered_set<int>visited;
        int n = nums.size();
        int result = -1;
        for(auto num:nums){
            if(num >= n || num < 0)return -1;
            if(visited.count(num) != 0)result = num;
            visited.insert(num);
        }
        return result;
    }
};
