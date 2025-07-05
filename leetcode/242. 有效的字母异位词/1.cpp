#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<char, int> map;
        if (s.length() < t.length())
            return false;
        for (int i = 0; i < s.length();++i)
            map[s[i]]++;
        for (int i = 0; i < t.length();++i)
            map[t[i]]--;
        for (auto &[key, value] : map)
            if (value != 0)
                return false;
        return true;
    }
};