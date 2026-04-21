/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-12 15:08:14
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-12 15:20:08
 */
class Solution {
public:
    void reverseRange(string &s,int left,int right){
        while(left < right-1){
            swap(s[left],s[right-1]);
            ++left;
            --right;
        }
    }

  string reverseStr(string s, int k) {
    for(int i = 0;i<s.size();i+=2*k){
        if(i + k <= s.size()){
            reverseRange(s,i,i+k);
            continue;
        }
        reverseRange(s,i,s.size());
    }
    return s;
  }
};
