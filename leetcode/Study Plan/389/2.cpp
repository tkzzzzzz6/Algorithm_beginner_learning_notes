//计数

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        vector<int> cnt(26,0);
        for(char c:s){
            cnt[c - 'a']++;
        }
        for(char c:t){
            cnt[c - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(cnt[i] < 0)return 'a' + i;
        }
        return ' ';
    }
};

int main()
{
    Solution sol;
    string s = "abcd";
    string t = "abcde";
    cout << sol.findTheDifference(s, t) << endl; // 输出："e"
    return 0;
}