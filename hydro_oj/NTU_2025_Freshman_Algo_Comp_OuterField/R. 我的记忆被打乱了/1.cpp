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

vector<int>a;

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0;i<n;++i)cin >> a[i];

    while(m--){
        int i;
        cin >> i;
        cout << a[i-1];
        if(m>0)cout << ' ';
    }
    cout << '\n';

    return 0;
}
