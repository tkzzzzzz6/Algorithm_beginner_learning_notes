/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-18 23:22:22
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-18 23:34:24
 */

#include <algorithm>
#include <iostream>
#include <vector>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);

il void solve() {
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  sort(a.begin(), a.end());
  int l = 0, ans = 0;
  for (int r = 0; r < n; ++r) {
    while (a[r] - a[l] > 2 * p) {
      ++l;
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans;
}

int main() {
  fastio;

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
