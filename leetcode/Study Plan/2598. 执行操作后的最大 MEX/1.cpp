#include <bits/stdc++.h>
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;

     
        for (auto x : nums) {
            int mod = ((x % value) + value) % value;
            mp[mod]++;
        }

        int mex = 0;
        while (mp[mex % value] > 0) {
            mp[mex % value]--;
            mex++;
        }

        return mex;
    }
};