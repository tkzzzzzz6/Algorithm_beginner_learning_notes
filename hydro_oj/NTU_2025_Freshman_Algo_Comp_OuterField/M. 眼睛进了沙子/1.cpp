#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        vector<string> s(3);
        for(int i = 0; i < 3; ++i) {
            cin >> s[i];
        }
        swap(s[0], s[2]);
        cout << s[0] << ' ' << s[1] << ' ' << s[2] << '\n';
    }

    return 0;
}
