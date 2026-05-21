/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-16 14:15:23
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-20 22:38:09
 */
/*
* @acwing app=acwing.cn id=3216 lang=C++
*
* 3213. 数字排序
*/

// @acwing code start
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
const int N = 1010;

int main(){
    int n;
    if(!(cin >> n)) return 0;
    vector<int> cnt(N);
    for(int i = 0;i<n;++i){
        int x;cin >> x;
        cnt[x]++;
    }

    struct Data{
        const int *cnt;
        Data(const int* c = nullptr):cnt(c){}
        bool operator()(int a,int b)const{
            if(cnt[a] != cnt[b])return cnt[a] > cnt[b]; //频次降序
            return a < b; //值升序
        }
    };

    set<int,Data> s{Data(cnt.data())};
    for(int i = 0;i<N;++i){
        if(cnt[i])s.insert(i);
    }

    for(int v:s)cout << v <<  ' ' << cnt[v] << endl;

    return 0;
}


// @acwing code end
