/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-08 10:35:53
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-08 10:39:50
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 求序列a中的峰、谷点的个数
     * @param a int整型vector 序列a
     * @return int整型
     */
    int countPeakPoint(vector<int> &a) {
        // write code here
        int n = a.size();
        int ans = 0;
        for (int l = 1; l + 1 < n; ++l) {
            if (a[l + 1] > a[l] && a[l - 1] > a[l] || a[l + 1] < a[l] && a[l - 1] < a[l])
                ++ans;
        }
        return ans;
    }
};
