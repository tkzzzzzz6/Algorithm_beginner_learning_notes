#include <string>
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-05 18:50:48
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-05 18:50:52
 */
class Solution {
public:
  bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (auto c : moves) {
      switch (c) {
      case 'R':
        ++x;
        break;
      case 'L':
        --x;
        break;
      case 'U':
        ++y;
        break;
      case 'D':
        --y;
        break;
      }
    }
    if (x == 0 && y == 0) {
      return true;
    }
    return false;
  }
};
