#include <string>
class Solution {
public:
  bool checkStrings(string s1, string s2) {
    int cnt1[2][26]{}, cnt2[2][26]{};
    for (int i = 0; i < s1.length(); ++i) {
      cnt1[i % 2][s1[i] - 'a']++;
      cnt2[i % 2][s2[i] - 'a']++;
    }
    return memcmp(cnt1, cnt2, sizeof(cnt1)) == 0;
  }
};
