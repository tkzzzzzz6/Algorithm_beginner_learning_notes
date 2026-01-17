class Solution {
  int f(vector<int> &a) {
    ranges::sort(a);
    int mx = 1, cnt = 1;
    for (int i = 1; i < a.size(); ++i) {
      if (a[i] == a[i - 1] + 1) {
        cnt++;
        mx = max(mx,cnt);
      } else {
        cnt = 1;
      }
    }
    return mx;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
      int side = min(f(hBars), f(vBars)) + 1;
      return side * side;
    }
};
