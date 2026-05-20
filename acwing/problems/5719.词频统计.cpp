/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-20 22:03:31
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-20 22:14:34
 */
/*
* @acwing app=acwing.cn id=5722 lang=C++
*
* 5719. 词频统计
*/

// @acwing code start
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int cnt[N],tot[N]; //分别用来存储单词在多少篇文章中出现过以及在所有文章中总出现次数
bool st[N]; // 用来判断单词在当前文章中是否出现过


int main(){

    int n,m;
    cin >> n >> m;

    while(n--){
        int k;
        cin >> k;

        memset(st,false,sizeof(st));
        while(k--){
            int x;
            cin >> x;
            tot[x]++;
            if(!st[x])
            {
                cnt[x]++;
                st[x] = true;
            }
        }
    }

    for(int i = 1;i<=m;++i){
        cout << cnt[i] << ' ' << tot[i] << endl;
    }

    return 0;
}

// @acwing code end
