
#include <vector>
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int>result;
    unordered_set<int>nums_set(nums1.begin(),nums1.end());
    for(auto x:nums2){
        if(nums_set.find(x) != nums_set.end()){
            result.insert(x);
        }
    }
    return vector<int>(result.begin(),result.end());
  }
};
