#include <bits/stdc++.h>

using namespace std;

using ll= long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;cin >> n;
    vector<int> locations;
    int f = -1;

    for(int i = 0;i<n;++i)
    {
        int num;cin >> num;
        if(num&1)
            locations.push_back(i);
    }
    ll ans = 0;
    for(int i:locations)
    {
        ans+=(n-i)*(i-f);
        f = i;
    }
    cout << ans;
}
