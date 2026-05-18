/*
* @acwing app=acwing.cn id=3216 lang=C++
*
* 3213. 数字排序
*/

// @acwing code start
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int cnt[N];
struct Data{
    int v,c;
    bool operator < (const Data & t) const
    {
        if(c != t.c)return c > t.c;
        return v < t.v;
    }
}q[N];

int main(){
    int n;cin >> n;
    for(int i = 0;i<n;++i){
        int x;cin >> x;
        cnt[x]++;
    }

    n = 0;
    for(int i =0;i<N;++i){
        if(cnt[i])
            q[n++] = {i,cnt[i]};
    }

    sort(q,q+n);

    for(int i = 0;i<n;++i){
        cout << q[i].v << ' ' << q[i].c << endl;
    }

    return 0;
}

// @acwing code end
