#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    for (int i = 0; i < strs[0].size(); ++i) {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); ++j) {
            if (i == strs[j].size() || strs[j][i] != c) {
                return strs[0].substr(0, i);
            }
        }
    }

    return strs[0];
}

int main() {
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs1) << endl; // 输出 "fl"

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs2) << endl; // 输出 ""

    return 0;
}
