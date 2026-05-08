#include <vector>
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-12 14:43:32
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-12 14:43:59
 */
class Solution {
public:
  void reverseString(vector<char> &s) {
    int n = s.size();
    int left = 0,right = n -1;
    while(left < right){
        swap(s[left],s[right]);
        ++left;
        --right;
    }
  }
};
