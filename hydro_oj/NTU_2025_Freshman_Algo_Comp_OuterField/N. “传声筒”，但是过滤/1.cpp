#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        if(str.find("like") != string::npos || str.find("love") != string::npos) continue;
        else cout << str << endl;
    }

    return 0;
}
