/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-02 21:39:02
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-02 21:58:35
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

const ull MOD = 2000120420010122;


il void solve(){
    string s;
    while(getline(cin,s)){
        ull dp[4] = {0,0,0,0};
        // dp[0] 'c'的方案数
        // dp[1] 'cw'的方案数
        // dp[2] 'cwb'的方案数
        // dp[3] 'cwbc'的方案数
        const ull base = 1;

        for(unsigned char ch:s){
            char x = (char)tolower(ch);
            if(x == 'c'){
                dp[3] += dp[2];
                if(dp[3] >= MOD){
                    dp[3] %= MOD;
                }
                // 对于开头'c'的方案处理
                dp[0] += base;
                if(dp[0] >= MOD){
                    dp[0] %= MOD;
                }
            }else if(x == 'w'){
                dp[1] += dp[0];
                if(dp[1] >= MOD){
                    dp[1] %= MOD;
                }
            }else if(x == 'b'){
                dp[2] += dp[1];
                if(dp[2]>=MOD){
                    dp[2] %= MOD;
                }
            }
        }
        cout << dp[3] % MOD << endl;
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
