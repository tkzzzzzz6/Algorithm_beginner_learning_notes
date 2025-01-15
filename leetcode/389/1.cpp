#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<char> v;
        for(int i=0;i<t.size();i++){
            v.push_back(t[i]);
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<v.size();j++){
                if(s[i]==v[j]){
                    v.erase(v.begin()+j);
                    break;
               }
            }
        }
        return v[0];
    }
};

int main() {
    Solution sol;
    string s = "abcd";
    string t = "abcde";
    cout << sol.findTheDifference(s, t) << endl; // 输出："e"
    return 0;
}