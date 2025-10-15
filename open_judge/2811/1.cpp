#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};
int g[5][6], backup[5][6], res[5][6];

void turn(int a,int b){
    res[a][b] = 1;
    for (int i = 0;i < 5;++i){
        int x = a + dx[i];
        int y = b + dy[i];
        if(x < 0 || y < 0 || x >= 5 || y >= 6)
            continue;
        g[x][y] ^= 1;
    }
    
}

int main()
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            cin >> g[i][j];
        }
    }

    memcpy(backup, g, sizeof g);
    for (int op = 0; op < (1<<6);++op){
        memcpy(g, backup, sizeof backup);
        memset(res, 0, sizeof res);

        for (int j = 0;j < 6;++j){
            if(op >> j & 1)
                turn(0,j);
        }

        for (int i = 0;i < 4;++i){
            for (int j = 0; j < 6;++j){
                if(g[i][j] == 1)
                    turn(i+1,j);
            }
        }

        bool dark = true;
        for (int i = 0;i < 6;++i){
            if(g[4][i] == 1){
                dark = false;
                break;
            }
        }

        if(dark){
            for(int i = 0;i < 5;++i){
                for(int j = 0;j < 6;++j){
                    cout << res[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
            
    }
    return 0;
}
