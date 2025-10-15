#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const int N = 1 << 30;

int ans;
set<int> s;

int main(){
    for (int i = 0, j; i < N;++i){
        int cur = 0;
        for (j = 0; j < 30;++j){
            if(i & ( 1 << j)){
                if(cur + 10 == 100)
                    break;
            }
            else
                cur = 0;
            if(cur == 70){
                int pre = i & ((1 << (j + 1)) - 1);
                if(!s.count(pre)){
                    ++ans;
                    s.insert(pre);
                }
            }
        }
    }

    return cout << ans << endl, 0;
}