/*
* @acwing app=acwing.cn id=3205 lang=C++
*
* 3202. 相邻数对
*/

// @acwing code start
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N];

int main(){
    int n;cin >> n;
    for(int i = 1;i<=n;++i)
        cin >> a[i];

    sort(a+1,a+n+1);

    int res = 0;
    for(int i = 2;i<=n;++i){
        if(a[i] - a[i-1] == 1)res++;
    }
    
    cout << res <<endl;

    return 0;
}

// @acwing code end
