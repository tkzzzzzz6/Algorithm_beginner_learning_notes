#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

void _(){
    int a,b;
    cin >> a >> b;
    int n = ceil(sqrt(max(a,b) * 2 - 1));
    if(n*n<a+b){
        ++n;
    }
    cout << n << '\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T = 3;
    cin >> T;
    while(T--){
        _();
    }

    return 0;
}
