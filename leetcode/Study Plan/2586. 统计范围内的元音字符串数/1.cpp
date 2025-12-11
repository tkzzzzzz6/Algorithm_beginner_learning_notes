#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        string vowels = "aeiou";
        int ans = 0;
        for(int i = left;i<=right;++i)
        {
            ans += (vowels.find(words[i][0]) != string::npos) 
            && (vowels.find(words[i].back()) != string::npos);
        }
        return ans;
    }
};
