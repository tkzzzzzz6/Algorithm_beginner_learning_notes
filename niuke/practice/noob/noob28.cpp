
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int time;
    cin >> time;

    int month = time % 100;
    if (3 <= month && month <= 5)cout << "spring\n";
    else if (6 <= month && month <= 8)cout << "summer\n";
    else if (9 <= month && month <= 11)cout << "autumn\n";
    else cout << "winter\n";


    return 0;
}