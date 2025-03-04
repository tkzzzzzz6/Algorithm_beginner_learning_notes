#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
// #include <numeric>

using namespace std;



int main()
{

    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int gcd = std::__gcd(a[0], a[2]);
    printf("%d/%d", a[0] / gcd, a[2] / gcd);
    return 0;
}
