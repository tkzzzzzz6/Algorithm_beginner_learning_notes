/*
* @acwing app=acwing.cn id=3210 lang=C++
*
* 3207. 门禁系统
*/

// @acwing code start
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;
int a[N];

int main(){
    cin >> n;
    while(n--){
        int x;cin >> x;
        a[x]++;
        cout << a[x] << ' ';
    }
    return 0;
}

// @acwing code end
