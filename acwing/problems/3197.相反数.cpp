/*
 * @acwing app=acwing.cn id=3200 lang=C++
 *
 * 3197. 相反数
 */

// @acwing code start
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1005;
int s[N];

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        s[abs(x)]++;
    }

    int res = 0;
    for(auto x:s)
        if(x == 2)
            res++;

    cout << res << endl;

    return 0;
}

// @acwing code end
