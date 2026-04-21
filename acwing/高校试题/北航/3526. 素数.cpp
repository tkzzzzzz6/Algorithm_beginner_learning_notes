#include <iostream>
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-13 11:23:16
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-14 01:42:29
 */
/*
* @acwing app=acwing.cn id=3529 lang=C++
*
* 3526. 素数
*/

// @acwing code start
#include<iostream>

using namespace std;

bool is_prime(int x){
    if(x < 2 || x % 2 == 0)return false;
    for(int i = 2;i<=x/i;++i){
        if(x % i == 0)return false;
    }
    return true;
}

int main(){
    int n;
    while(cin >> n){
        int cnt = 0;
        for(int i = 2;i<n;i = (i / 10 + 1)*10 + 1){
            if(is_prime(i)){
                ++cnt;
                cout << i << ' ';
            }
        }
        if(!cnt) cout << -1;
        cout << endl;
    }
    return 0;
}

// @acwing code end
