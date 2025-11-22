#include<bits/stdc++.h>
#define il inline
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
    int n;
    cin >> n;
    unordered_map<int,int> mp;
    for (int i = 0; i < n;++i)
    {
        int x;
        cin >> x;
        if(mp.count(x) > 1)
        {
            cout << "NO" << endl;
            return;
        }else{
            mp[x]++;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    fastio
    
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     if (!(cin >> n))
//         return 0;

//     // 可以用 unordered_map<int,int> freq; 这里只是为了快用 vector
//     vector<int> freq(n + 2, 0);
//     for (int i = 0; i < n; ++i)
//     {
//         int x;
//         cin >> x;
//         if (x <= n)
//             freq[x]++; // 学号只在 1..n 之间
//         else
//         { // 若题目允许更大，可以存 freq 里，但题设是 ≤ n
//             cout << "NO\n";
//             return 0;
//         }
//     }

//     long long available = 0; // 当前“尚可分配”的学号 ≥ i 的同学数
//     for (int seat = 1; seat <= n; ++seat)
//     {
//         available += freq[seat]; // 学号 == seat 的同学加入池子
//         if (available == 0)
//         { // 没人能坐 seat，上一步就失败
//             cout << "NO\n";
//             return 0;
//         }
//         --available; // 分配一个给当前座位
//     }

//     cout << "YES\n";
//     return 0;
// }