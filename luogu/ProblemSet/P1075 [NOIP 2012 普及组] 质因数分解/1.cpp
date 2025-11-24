#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 2;i<=n;++i)
    {
        if(n%i == 0)
        {
            cout << n/i << endl;
            return 0;
        }
    }

    return 0;
}
