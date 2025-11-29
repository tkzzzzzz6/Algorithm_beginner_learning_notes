#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int n,m;
char mp[1020][1020];
int ans[1020][1020];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void find(int x,int y)
{
    if(mp[x][y] == '*')
    {
        for(int i = 0;i<8;++i)
        {
            ans[x+dx[i]][y+dy[i]]++;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i =1;i<=n;++i)
    {
        for(int j =1;j<=m;++j)
        {
            cin >> mp[i][j];
            find(i,j);
        }
    }

    for(int i = 1;i<=n;++i)
    {
        for(int j = 1;j<=m;++j)
        {
            if(mp[i][j] == '*')
                cout << '*';
            else
                cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
