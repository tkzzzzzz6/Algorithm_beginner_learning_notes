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

vector<vector<int>> pos(26);


il void solve(){
    string B;
    cin >> B;

    int cur_pos = -1;
    bool isSubseq = true;
    for(auto ch:B)
    {
        int idx = ch - 'a';
        auto it = upper_bound(pos[idx].begin(),pos[idx].end(),cur_pos);
        if(it == pos[idx].end())
        {
            isSubseq = false;
            break;
        }
        cur_pos = *it;
    }
    cout << (isSubseq ? "Yes" : "No") << endl;
}

int main()
{
    fastio;
    string A;
    cin >> A;

    int len_A = A.length();

    for(int i = 0;i<len_A;++i)
    {
        pos[A[i] - 'a'].pb(i);
    }

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
