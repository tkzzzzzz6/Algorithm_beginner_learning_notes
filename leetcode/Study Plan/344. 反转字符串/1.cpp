#include <vector>
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-12 14:43:32
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-12 14:47:46
 */
class Solution {
public:
  void reverseString(vector<char> &s) {
    int n = s.size();
    for(int i = 0,j = n - 1;i<n/2;++i,--j){
        swap(s[i],s[j]);
    }
  }
};
