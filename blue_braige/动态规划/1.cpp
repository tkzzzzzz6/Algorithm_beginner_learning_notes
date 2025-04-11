#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int T, n;
int c[N];
int mem[N];
int sum = 0;

int dfs(int x){
    if(mem[x])
        return mem[x];
    if(x > n)
        sum =  0;
    else
        sum = max(dfs(x + 1), dfs(x + 2) + c[x]);
}

int main(){

    vector<int> c(N);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for (int i = 0; i < n;++i){
            scanf("%d", &c[i]);
        }
        memset(mem, 0, sizeof(mem));
        int res = dfs(0);
        printf("%d", res);
    }
    return 0;
}