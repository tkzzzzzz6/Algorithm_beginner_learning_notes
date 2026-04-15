/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-07 11:22:13
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-07 11:34:44
 */
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param tickets int整型vector
   * @param k int整型
   * @return int整型
   */
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    // write code here
    int n = tickets.size(),ans = 0;
    for(int i = 0;i<n;++i){
        if(i <= k){
            ans += min(tickets[k],tickets[i]);
        }else{
            ans += min(tickets[k] - 1,tickets[i]);
        }
    }
    return ans;
  }
};
