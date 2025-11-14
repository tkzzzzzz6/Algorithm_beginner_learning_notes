#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

    int L = min(n, m);
    long long diff = 0;
    for (int i = 0; i < L;++i){
        if(s1[i] != s2[i])
            ++diff;
    }
    long long ans = diff + llabs((ll)n -(ll)m);
    cout << ans << '\n';
    return 0;
}