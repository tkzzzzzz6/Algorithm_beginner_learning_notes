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
    if(n == 0){
        cout << '1';
        return 0;
    }
    cout << '1';
    while(n--){
        cout << '0';
    }

    return 0;
}
