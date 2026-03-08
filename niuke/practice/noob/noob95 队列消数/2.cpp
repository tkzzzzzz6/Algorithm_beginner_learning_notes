/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-07 11:22:13
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-07 11:54:07
 */
#include <queue>
#include <vector>
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
    queue<int> q;
    int time = 0;
    for(auto t:tickets)
        q.push(t);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ++time;
        tickets[cur]--;
        if(tickets[cur] > 0){
            q.push(cur);
        }else if(cur == k){
            return time;
        }
    }
    return time;
  }
};
