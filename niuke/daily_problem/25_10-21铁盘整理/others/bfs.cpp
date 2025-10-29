#include <bits/stdc++.h>
using namespace std;

int a[1010];

int n;
int mi;
int check() {
    int cnt = 0, i;
    for (i = 2; i <= n + 1; i++) {
        if (abs(a[i] - a[i - 1]) != 1)cnt++;
    }
    return cnt;
}
int dep;
void dfs(int p, int cnt) {
    // cout<<p<<" "<<cnt<<" "<<check()<<" "<<mi<<'\n';
    int i, j;
    if (check() + cnt > dep || mi)return;
    if (check() == 0) {
        mi = dep;
        return;
    }
    // for(i=1;i<=n;++i)cout<<a[i]<<" ";
    // cout<<'\n';
    for (j = 2; j <= n; j++) {
        if (j == p || abs(a[j] - a[j + 1]) == 1)continue;
        for (i = 1; i <= j / 2; i++) {
            swap(a[i], a[j - i + 1]);
        }
        dfs(j, cnt + 1);
        for (i = 1; i <= j / 2; i++) {
            swap(a[i], a[j - i + 1]);
        }
    }

}
int main() {
    map<int, int>mp;
    int j = 1, i;
    cin >> n;
    for (i = 1; i <= n; i++)cin >> a[i], mp[a[i]] = 1;
    for (auto i : mp)mp[i.first] = j++;
    for (i = 1; i <= n; i++)a[i] = mp[a[i]];
    a[n + 1] = n + 1;
    mi = 0;
    dep = check();
    while (!mi)dfs(0, 0), dep++;
    cout << mi;
}