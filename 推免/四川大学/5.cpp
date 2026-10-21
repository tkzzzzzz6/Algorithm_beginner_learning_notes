#include <iostream>

using namespace std;

const int MOD = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0,f1 = 1 ,f2 = 1;

    if (n == 0) {
        cout << '1\n';
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        int temp = f1;
        f1 = f2;
        f2 = (temp + f2) % MOD;
    }



	return 0;
}