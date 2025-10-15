#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int h,r;
    cin >> h >> r;
    double v = 3.14*r*r*h;
    int ans = ceil(20*1e3/v);
    cout << ans << endl;
    return 0;
}