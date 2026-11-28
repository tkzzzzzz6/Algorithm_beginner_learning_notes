#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    while (n > 0) {
        int a = n % 2;
        if (a == 1) {
            ++ans;
        }
        n >>= 1;
    }
    cout << ans << endl;
}
