/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-09 00:02:12
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-09 00:02:31
 */
#include <iostream>
using namespace std;

int main() {
  auto f = [](auto &&f, int p, int q) -> void {
    if (p % q == 0) {
      cout << (p / q);
      return;
    }
    cout << (p / q) << "+1/";
    if (q % (p % q) != 0) {
      cout << '{';
    }
    f(f, q, p % q);
    if (q % (p % q) != 0) {
      cout << "}";
    }
  };

  int t;
  cin >> t;
  while (t--)
    [&]() -> void {
      int p, q;
      cin >> p >> q;
      cout << p << "/" << q << " = ";
      f(f, p, q);
      cout << '\n';
    }();

  return 0;
}
// 64 位输出请用 printf("%lld")
