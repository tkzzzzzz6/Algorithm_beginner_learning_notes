/*
* @acwing app=acwing.cn id=3206 lang=C++
*
* 3203. 画图
*/

// @acwing code start
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 101;
int a[N],b[N],c[N],d[N];
int x,y;

int main(){
    int n;cin >> n;
    int res = 0;
    for(int i = 1;i<=n;++i){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for(int x = 0;x<=100;++x)
        for(int y = 0;y<=100;++y)
            for(int i = 1;i<=n;++i){
                if(x >= a[i] && y >= b[i] && x+1 <= c[i] && y+1 <= d[i]){
                    res++;
                    break;
                }
            }

    cout << res << endl;

    return 0;
}

// @acwing code end
