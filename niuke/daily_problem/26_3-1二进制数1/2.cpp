#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    while (n > 0) {
        n &= (n-1);
        ++ans;
    }
    cout << ans << endl;
}
