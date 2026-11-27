#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long l, a, b;
        cin >> l >> a >> b;
        cout << l / lcm(gcd(l, a), gcd(l, b)) << '\n';
    }
    return 0;
}
