#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int used_time = (c - a) * 60 + d - b;
    cout << used_time / 60 << " " << used_time % 60 << endl;
    return 0;
}