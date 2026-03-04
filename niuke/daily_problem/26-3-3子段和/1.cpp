/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-03 09:08:54
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-03 09:08:59
 */
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0;i<n;++i){
        int x;
        cin >> x;
        if(x == 0){
            cout << "NO" << endl;
            return 0;
        }
        s.insert(x);
    }
    if(s.size() == 2 && *s.begin() + *s.rbegin() == 0){
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }
}
