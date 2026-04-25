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
        int n,m;
        cin >> n >> m;
        int large=0,equal = 0,less = 0;
        for(int i = 0;i<n;++i){
            int x;
            cin >> x;
            if(x > m) large++;
            else if(x == m) equal++;
            else less++;
        }
        cout << equal << ' ' << large << ' ' << less << '\n';
    }

    return 0;
}
