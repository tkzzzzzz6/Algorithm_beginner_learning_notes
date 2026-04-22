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

string s;

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t;
    cin >> t;
    int cnt_0 = 0;
    for(int i = 0;i<t;++i){
        int x;
        cin >> x;
        if(x == 0)cnt_0++;
    }

    if(cnt_0 == t){
        for(int i = 0;i<cnt_0;++i){
            s+='0';
            if(i<cnt_0-1)s+=' ';
        }
        s+='\n';
        cout << s;
        return 0;
    }
    for(int i = 0;i<cnt_0;++i)s+="0 ";
    for(int i = 1;i<(t-cnt_0);++i)s+="1 ";
    s+="1\n";

    cout << s;

    return 0;
}
