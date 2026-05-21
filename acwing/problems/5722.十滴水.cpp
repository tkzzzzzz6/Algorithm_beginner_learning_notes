/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-21 13:20:18
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-21 21:50:15
 */
/*
* @acwing app=acwing.cn id=5725 lang=C++
*
* 5722. 十滴水
*/

// @acwing code start
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define x first
#define y second

typedef pair<int,int> PII; //PII.x 表示坐标,PII.y表示权值
const int N = 3e5 + 10;

int l[N],r[N],w[N];
// l[i]记录i的左邻居
// r[i]记录i的右邻居
// w[i]记录i的权值
unordered_map<int,int>pos;

PII p[N];

int c,n,m;


int main(){
    scanf("%d%d%d",&c,&m,&n);
    for(int i = 1;i<=m;++i)scanf("%d%d",&p[i].x,&p[i].y);
    sort(p+1,p+m+1); //题目中的元素大小可能是随机的

    for(int i = 1;i<=m;++i){
        l[i] = i-1;r[i] = i + 1;
        w[i] = p[i].y;
        pos[p[i].x] = i;
    }

    int res = m;
    while(n--)
    {
        // 处理第一次水滴
        int x;
        scanf("%d",&x);
        int k = pos[x];
        w[k]++;

        while(w[k] >= 5)
        {
            res--;
            int nk = 0,L = l[k],R = r[k];
            r[L] = R,l[R] = L;//L-k-R,删除k
            if(R <= m && ++w[R] >= 5)nk = R;
            if(L && ++w[L] >= 5)nk = L; //左边会覆盖右边的,左边的优先级更高
            k = nk;
        }

        printf("%d\n",res);
    }
    return 0;
}

// @acwing code end
