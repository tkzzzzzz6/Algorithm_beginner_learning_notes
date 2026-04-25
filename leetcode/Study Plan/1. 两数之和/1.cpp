#include <vector>
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-11 10:32:07
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-11 10:32:11
 */
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int,int>visited;
    for(int i = 0;i<nums.size();++i){
        int s = target - nums[i];
        auto iter = visited.find(s);
        if(iter != visited.end()){
            return {i,iter->second};
        }
        visited.insert({nums[i],i});
    }
    return {};
  }
};
