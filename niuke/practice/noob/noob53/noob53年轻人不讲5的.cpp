#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    string str;
    cin >> str;
    for(char &s : str)
    {
        if(s == '5')
            s = '*';
    }
    cout << str;

    return 0;
}
