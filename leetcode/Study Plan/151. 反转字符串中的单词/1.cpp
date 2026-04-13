/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-12 15:32:25
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-13 08:43:36
 */
class Solution {
public:
  void reverseRange(string &s, int left, int right) {
    for (; left < right; ++left, --right) {
      swap(s[left], s[right]);
    }
  }

  void removeExtSpace(string &s) {
    int slow = 0;
    for (int fast = 0; fast < s.size(); ++fast) {
      if (s[fast] != ' ') {
        if (slow != 0)s[slow++] = ' ';
        while(fast < s.size() && s[fast] != ' ')
            s[slow++] = s[fast++];
      }
    }
    s.resize(slow);
  }

  string reverseWords(string s) {
    removeExtSpace(s);
    reverse(s.begin(), s.end());
    int start = 0;
    for (int i = 0; i <= s.size(); ++i) {
      if (i == s.size() || s[i] == ' ') {
        reverseRange(s, start, i-1);
        start = i + 1;
      }
    }
    return s;
  }
};
