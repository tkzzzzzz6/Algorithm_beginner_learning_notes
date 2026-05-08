/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-28 09:41:21
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-28 09:41:40
 */
/**
 * @nc app=nowcoder id=020a0cf673174d5795d97ae79cff59a0 topic=225 question=2177130 lang=C++
 * 2026-04-28 09:41:21
 * https://www.nowcoder.com/practice/020a0cf673174d5795d97ae79cff59a0?tpId=225&tqId=2177130
 * [CPP2] 实现四舍五入
 */

/** @nc code=start */

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

const ll N = 5e5+5, mod = 1e9+7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

il void solve(){
    double t;
    cin >> t;
    cout << round(t) << endl;
    // cout << (long long)(t + 0.5); //只适用非负数
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

/** @nc code=end */
