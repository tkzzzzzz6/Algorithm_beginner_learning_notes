/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-28 17:53:40
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-28 17:53:44
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        vector<int> a;
        cin >> n;
        a.resize(n);
        for(int i = 0;i<n;++i){
            cin >> a[i];
        }
        cout << a[0] << endl;
    }
}
// 64 位输出请用 printf("%lld")
