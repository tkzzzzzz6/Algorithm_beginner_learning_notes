#include <bits/stdc++.h>
using namespace std;

int a[1010];

int n;
int res;
int check() {
    int cnt = 0, i;
    for (i = 2; i <= n + 1; i++) {
        if (abs(a[i] - a[i - 1]) != 1)cnt++;
    }
    return cnt;
}
int mi;
int dep;
void dfs(int p, int cnt) {
    int i, j;
    //   if(check()+cnt>dep||res)return;
    if (check() + cnt >= mi) {
        return;
    }
    if (check() == 0) {
        // res=dep;
        mi = min(mi, cnt);
        return;
    }
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
    mi = 2 * n;
    dep = check();
    dfs(0, 0);
    // while(!res)dfs(0,0),dep++;
    cout << mi;
    // cout<<res;
}