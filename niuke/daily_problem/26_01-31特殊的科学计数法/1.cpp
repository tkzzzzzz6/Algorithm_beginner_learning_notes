/*
 * @Author: tkzzzzzz6
 * @Date: 2026-01-31 19:46:23
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-01-31 20:03:21
 */
#include<bits/stdc++.h>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio \
ios::sync_with_stdio(false); \
cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;


il void solve(){
    string n;
    cin >> n;
    if(n.size() == 1){
        cout << n[0] << "*10^" << "0\n";
    }
    if(n.size() == 2){
        cout << n[0] << '.' << n[1] << "*10^" << "1\n";
    }else{
        if(n[2] < 5){
            cout << n[0] << '.' << n[1] << "*10^" << "1\n";
        }else{
            if(n[1] == 9){
                if(n[0] == 9){
                    n[0] = 1,n[1] = 0;
                    cout << n[0] << '.' << n[1] << "*10^" << n.size() - 1 << "\n";
                }else{
                    n[0] += 1, n[1] = 0;
                    cout << n[0] << '.' << n[1] << "*10^" << n.size() - 2 << "\n";                }
            }else{
                n[1] += 1;
                cout << n[0] << '.' << n[1] << "*10^" << n.size() - 2 << "\n";
            }
        }
    }
}

int main()
{
    fastio;
    
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
