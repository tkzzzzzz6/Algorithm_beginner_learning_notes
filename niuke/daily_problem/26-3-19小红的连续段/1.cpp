#include <iostream>
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-19 23:45:17
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-19 23:55:29
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static constexpr ll MOD = 1e9 + 7;
static constexpr ll MAX_VAL = 1000;

template <ll N> struct Combination {
  array<array<ll, N + 1>, N + 1> data{};

  constexpr Combination() {
    for (int i = 0; i <= N; i++) {
      data[i][0] = 1;
      for (int k = 1; k <= i; k++) {
        data[i][k] = (data[i - 1][k - 1] + data[i - 1][k]) % MOD;
      }
    }
  }

  constexpr ll get(int n, int k) const {
    if (k < 0 || k > n)
      return 0;
    return data[n][k];
  }
};

static const Combination<MAX_VAL> comb;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x, y;
  cin >> x >> y;

  for (ll i = 1; i <= x + y; i++) {
    ll k = i / 2;
    ll ans;
    if (i % 2 == 0) {
      ans = 2LL * comb.get(x - 1, k - 1) * comb.get(y - 1, k - 1) % MOD;
    } else {
      ans = comb.get(x - 1, k) * comb.get(y - 1, k - 1) % MOD +
            comb.get(x - 1, k - 1) * comb.get(y - 1, k) % MOD;
      ans %= MOD;
    }
    cout << ans << endl;
  }
}
