#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double sum = 0;
    double ans = 0;
    cin >> n;

    vector<double> a(n);
    for (auto& x : a) {
        cin >> x;
        sum += x;
    }

    double avg = sum / n;

    for (int i = 0; i < n; ++i) {
        ans += (avg - a[i]) * (avg - a[i]);
    }

    ans /= n;

    cout << fixed << setprecision(2) << ans << '\n';

}