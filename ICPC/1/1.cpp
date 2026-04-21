#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long T;
    cin >> T;
    while(T--){
        unsigned long long x, y;
        cin >> x >> y;
        // if(x>y) swap(x,y);
        cout << "1 " << ((x * y) /(__gcd(x, y))/(__gcd(x, y))) << endl;
    }
    return 0;
}
