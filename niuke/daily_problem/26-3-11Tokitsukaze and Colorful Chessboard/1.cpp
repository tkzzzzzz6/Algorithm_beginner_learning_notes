/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-11 23:53:08
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-11 23:57:23
 */
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-11 23:53:08
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-11 23:53:12
 */
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    long long l = 0,r = 2e5;
    long long r1 = 2e5;
    while(l<=r){
        long long mid = l + ((r-l)>>1);
        if(mid*mid >= n+m&& ceil(1.0*mid *mid/2) >= max(n,m)){
            r1 = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << r1 << endl;
}

int main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
