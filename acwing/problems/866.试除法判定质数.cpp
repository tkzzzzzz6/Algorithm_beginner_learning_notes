/*
 * @acwing app=acwing.cn id=868 lang=C++
 *
 * 866. 试除法判定质数
 */

// @acwing code start
#include <iostream>
using namespace std;

void devided(int x) {
  for (int i = 2; i < x / i; ++i) {
    if (x % 2 == 0) {
      int s = 0; // s表示指数
      while (x % i == 0) {
        x /= i;
        s++;
      }
    }
    cout << "" <<
  }
}

int main() { return 0; }
// @acwing code end
