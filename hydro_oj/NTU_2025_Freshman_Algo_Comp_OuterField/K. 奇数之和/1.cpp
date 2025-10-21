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
    long long sum = 0;
    while(n--){
        int x;
        cin >> x;
        if(x%2 == 1)sum+=x;
    }

    cout << sum << '\n';

    return 0;
}
