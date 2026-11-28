#include <climits>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    int minN = INT_MAX, ans = 0;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        int sum = 0;
        for (char x : s) sum += x - '0';
        if (minN > sum) minN = sum, ans = i + 1;
    }
    cout << ans << endl;
    return 0;
}
