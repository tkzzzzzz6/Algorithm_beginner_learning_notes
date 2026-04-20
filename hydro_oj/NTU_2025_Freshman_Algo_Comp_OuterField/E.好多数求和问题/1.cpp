#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    long sum = 0;
    while(n--){
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum << endl;

    return 0;
}
