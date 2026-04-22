#include <bits/stdc++.h>

using namespace std;

int cnt = 1;

bool check(int x){
    if(x % 2 == 0)
        return false;
    for (int i = 3; i * i <= x;i+=2){
        if(x % i == 0)
            return false;
    }
    return true;
}

int main(){
    int cnt = 1;
    for (int i = 3; i <= 1000000;++i){
        if(check(i)){
            cnt++;
            if(cnt == 2025){
                cout << i;
                return 0;
            }
        }
    }
        return 0;
}