#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coefficients(n + 1);

    for (int i = 0; i <= n; ++i) {
        cin >> coefficients[i];
    }

    string ans;
    bool first = true;

    for (int i = 0; i <= n; ++i) {
        int value = coefficients[i];
        int power = n - i;

        if (value == 0) {
            continue;
        }

        int absoluteValue = abs(value);

        if (first) {
            if (value < 0) {
                ans += "-";
            }
            first = false;
        } else {
            ans += (value > 0) ? "+" : "-";
        }

        if (power == 0) {
            ans += to_string(absoluteValue);
        } else {
            if (absoluteValue != 1) {
                ans += to_string(absoluteValue);
            }

            ans += "x";

            if (power >= 2) {
                ans += "^" + to_string(power);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
