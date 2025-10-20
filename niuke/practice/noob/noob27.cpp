
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int max = INT_MIN, min = INT_MAX;

    int n = 3;
    while (n--) {
        int x;
        cin >> x;
        if (x > max)max = x;
        if (x < min)min = x;
    }

    cout << "The maximum number is : " << max << '\n';
    cout << "The minimum number is : " << min << '\n';

    return 0;
}