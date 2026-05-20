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

int partition_lomuto(int *q,int l,int r){
    int pivot_pos = l + rand() % (r - l + 1);
    swap(q[pivot_pos],q[r]);

    int x =q[r];
    int i = l -1;
    for(int j = l;j < r;++j){
        if(q[j] <= x){
            ++i;
            swap(q[i],q[j]);
        }
    }
    swap(q[i+1],q[r]);
    return i+1;
}
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int q[N];

int partition_lomuto(int *q,int l,int r){
    int pivot_pos = l + rand() % (r - l + 1);
    swap(q[pivot_pos],q[r]);

    int x =q[r];
    int i = l -1;
    for(int j = l;j < r;++j){
        if(q[j] <= x){
            ++i;
            swap(q[i],q[j]);
        }
    }
    swap(q[i+1],q[r]);
    return i+1;
}

void quick_sort(int *q,int l,int r){
    if(l >= r)return;

    int p = partition_lomuto(q,l,r);
    quick_sort(q,l,p-1);
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
void quick_sort(int *q,int l,int r){
    if(l >= r)return;

    int p = partition_lomuto(q,l,r);
    quick_sort(q,l,p-1);
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
