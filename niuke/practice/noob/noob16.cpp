
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    
    int seconds,hours,minutes;
    cin >> seconds;

    hours = seconds / 3600;
    seconds %= 3600;

    minutes = seconds / 60;
    seconds %= 60;

    cout << hours << ' ' << minutes << ' ' << seconds;



    return 0;
}