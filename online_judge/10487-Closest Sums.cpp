#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int N = 10, x = 6;
    // lower_bound将返回a中第一个大于等于x的元素的地址，计算出的i为其下标
    int i = lower_bound(a, a + N, x) - a;
    // 在以下两种情况下，a[i] (a中第一个大于等于x的元素) 即为答案：
    // 1. a中最小的元素都大于等于x；
    // 2. a中存在大于等于x的元素，且第一个大于等于x的元素 (a[i])
    // 相比于第一个小于x的元素 (a[i - 1]) 更接近x；
    // 否则，a[i - 1] (a中第一个小于x的元素) 即为答案
    if (i == 0 || (i < N && a[i] - x < x - a[i - 1]))
        cout << a[i];
    else
        cout << a[i - 1];
}
