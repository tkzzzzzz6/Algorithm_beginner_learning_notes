#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        for(int i=0;i<ransomNote.size();i++){
            size_t pos = magazine.find(ransomNote[i]);
            if(pos == string::npos){
                return false;
            }
            magazine.erase(pos, 1);
        }
        return true;
    }
};

int main() {
    string ransomNote = "aa";
    string magazine = "aab";
    Solution s;
    bool result = s.canConstruct(ransomNote, magazine);
    cout << (result ? "true" : "false") << endl;
    return 0;
}