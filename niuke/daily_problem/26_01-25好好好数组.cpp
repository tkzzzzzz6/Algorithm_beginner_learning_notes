/*
 * @Author: tkzzzzzz6
 * @Date: 2026-01-25 11:12:26
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-01-25 11:12:43
 */

#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    while(T--){
        int n,m;cin >> n >> m;
        if(m == 1){
            cout << n+1 << endl;
        }else if (m == 2){
            cout << n << endl;
        }else if(m == 3){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
}
