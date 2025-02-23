#include <iostream>
#include <cmath>
using namespace std;
    
int main() {
    int a[4], sum = 0;
    
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    
    long long result = 1;
    for (int i = 0; i < a[1]; i++) {
        result *= a[0];
    }
    result = result * a[2] + a[3];
    
    if (result % 2 == 0) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    
    return 0;
}