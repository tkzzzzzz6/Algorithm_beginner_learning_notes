#include <iostream>
#include <vector>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 1; i <= 100000000; ++i) {
        vector<int> digits;
        int x = i;
        while (x) {
            digits.push_back(x % 10);
            x /= 10;
        }
        int j = digits.size();
        if (j % 2 != 0) continue;

        int s1 = 0, s2 = 0;
        for (int k = 0; k < j / 2; ++k) {
            s1 += digits[k];
        }
        for (int k = j / 2; k < j; ++k) {
            s2 += digits[k];
        }
        if (s1 == s2) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}