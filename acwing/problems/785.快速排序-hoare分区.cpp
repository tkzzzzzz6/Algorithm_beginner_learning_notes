/*
 * @acwing app=acwing.cn id=787 lang=C++
 *
 * 785. 快速排序
 */

// @acwing code start
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int q[N];

int partition_hoare(int *q,int l,int r){
    int x = q[(l+r) >> 1];
    int i = l-1,j = r + 1;
    while(true){
        do i++;while(q[i] < x);
        do j--;while(q[j] > x);
        if(i >= j)return j;
        swap(q[i],q[j]);
    }
}

void quick_sort(int *q,int l,int r){
    if(l >= r)return;

    int p = partition_hoare(q,l,r);
    quick_sort(q,l,p);
    quick_sort(q,p+1,r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin >> n;
    for(int i =0;i<n;++i)cin >> q[i];

    quick_sort(q,0,n-1);

    for(int i = 0;i<n;++i)cout << q[i] << ' ';

    return 0;
}
// @acwing code end
