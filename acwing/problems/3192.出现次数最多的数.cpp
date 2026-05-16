/*
* @acwing app=acwing.cn id=3195 lang=C++
*
* 3192. 出现次数最多的数
*/

// @acwing code start

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;
int s[N];

int main(){
    int n;cin >> n;
    
    while(n--){
        int x;cin >> x;
        s[x]++;
    }

    int res = 0;
    for(int i = 1;i<N;++i){
        if(s[i] > s[res])res = i;
    }

    cout << res << endl;

    return 0;
}


// @acwing code end
