#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <numbers>
typedef long long ll;
using namespace std;

const double PI = acos(-1.0);

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while(t--){
        int r,a;
        cin >> r >> a;
        cout << cos(a*PI/180.0)*r << ' ' << r*sin(a*PI/180.0) <<'\n';
    }


    return 0;
}
