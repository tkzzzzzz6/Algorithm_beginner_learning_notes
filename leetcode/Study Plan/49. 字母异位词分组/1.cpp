#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto &s:strs)
        {
            string sorted_s = s;
            ranges::sort(sorted_s);
            mp[sorted_s].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &[_,v] : mp)
        {
            ans.push_back(v);
        }
        return ans;
    }
};
