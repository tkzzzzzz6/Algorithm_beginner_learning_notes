#include <bits/stdc++.h>

using namespace std;

int n = 0, m = 0;
int i = 0, j = 0;

int main(){
    cin >> n >> m >> i >> j;
    vector<vector<int>> a(n+1,vector<int>(m+1,0));

    a[0][0] = 1;
    for(int i = 1;i<=n;++i){
        a[i][0] = 1;
    }
    for(int i = 1;i<=m;++i){
        a[0][i] = 1;
    }
    if(0 <= i && i < n && j >= 0 && j < m)a[i][j] = 0;
    if(i-2 >= 0 && j-1 >= 0)a[i-2][j-1]=0;
    if(i-2 >= 0 && j+1 <= m)a[i-2][j+1]=0;
    if(i+2 <= n && j-1 >= 0)a[i+2][j-1]=0;
    if(i+2 <= n && j+1 <= m)a[i+2][j+1]=0;
    if(i-1 >= 0 && j-2 >= 0)a[i-1][j-2]=0;
    if(i-1 >= 0 && j+2 <= m)a[i-1][j+2]=0;
    if(i+1 <= n && j+2 <= m)a[i+1][j+2]=0;
    if(i+1 <= n && j-2 >= 0)a[i+1][j-2]=0;
    for(int x = 1;x<=n;++x){
        for(int y = 1;y<=m;++y){
                if(a[x][y] != 0){a[x][y] = a[x-1][y]+a[x][y-1];}
        }
    }
    // for(int x = 0;x<n;++x){
    //     for(int y = 0;y<m;++y){
    //         cout << setw(5) << a[x][y];
    //     }
    //     cout << endl;
    // }
    cout << a[n][m] << endl;
    return 0;
}