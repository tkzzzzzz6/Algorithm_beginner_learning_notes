#include <bits/stdc++.h>

using namespace std;

int main()
{

    double n;
    cin >> n;
    int cnt = 0;
    double power = 2.0; // Change int to double
    while (n > 0)
    {
        n -= power;
        power *= 0.98;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
