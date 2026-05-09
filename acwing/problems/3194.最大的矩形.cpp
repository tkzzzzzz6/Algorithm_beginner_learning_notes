/*
* @acwing app=acwing.cn id=3197 lang=C++
*
* 3194. 最大的矩形
*/

// @acwing code start
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
vector<int> h(N);

int main(){
    int n;cin >> n;
    for(int i = 1;i<=n;++i)cin >> h[i];

    int res = 0;
    for(int i = 1;i<=n;++i){
        int left = i,right = i;
        while(left >= 1 && h[left] >= h[i])--left;
        while(right <= n && h[right] >= h[i])++right;
        res = max(res,(right - left - 1)*h[i]);
    }

    cout << res << endl;

    return 0;
}

// @acwing code end
