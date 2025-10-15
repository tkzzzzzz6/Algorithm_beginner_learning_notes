#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if(ransomNote.size() > magazine.size())return false;
        vector<int> cnt(26);
        for(char c : magazine){
            cnt[c - 'a']++;
        }
        for(auto c:ransomNote){
            if(--cnt[c - 'a'] < 0)return false;
        }
        return true;
    }
};

int main()
{
    string ransomNote = "aa";
    string magazine = "aab";
    Solution s;
    bool result = s.canConstruct(ransomNote, magazine);
    cout << (result ? "true" : "false") << endl;
    return 0;
}