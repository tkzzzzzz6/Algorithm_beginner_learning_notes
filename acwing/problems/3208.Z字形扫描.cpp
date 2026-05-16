/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-14 13:15:30
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-15 13:48:29
 */
/*
* @acwing app=acwing.cn id=3211 lang=C++
*
* 3208. Z字形扫描
*/

// @acwing code start
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int g[2*N][2*N];

int main(){
    int n;cin >> n;
    for(int i = 1;i<=n;++i)
        for(int j =1;j<=n;++j)
            scanf("%d",&g[i][j]);

    for(int i = 2;i<=2*n;++i)
    {
        if(i % 2 == 0){ //奇数行开始
            // 左下到右上
            for(int j = i-1;j>=1;--j){
                if(j >= 1 && j <= n && i - j >= 1 && i - j <=n)
                    printf("%d ",g[j][i-j]);
            }
        }else{
            // 右上到左下
            for(int j = 1;j<=i-1;++j){
                if (j >= 1 && j <= n && i - j >= 1 && i - j <= n)
                    printf("%d ", g[j][i - j]);
            }
        }
    }

    return 0;
}

// @acwing code end
