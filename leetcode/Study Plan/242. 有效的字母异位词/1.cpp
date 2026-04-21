class Solution {
public:
  bool isAnagram(string s, string t) {
    int hash[26] = {0};
    if (s.size() != t.size()) // 如果s和t的长度不相同的话,不可能是异位词
      return false;

    for (auto c : s) {
      hash[c - 'a']++;
    }
    for (auto c : t) {
      hash[c - 'a']--;
    }
    for (int i = 0; i < 26; ++i) {
      if (hash[i] != 0)
        return false;
    }
    return true;
  }
};
