#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x){
    if(x <= 1)
        return false;
    for (int i = 2;i <=sqrt(x);i++){
        if(x % i == 0)
            return false;
    }
    return true;
}

int main(){
    int L;
    cin >> L;
    for(int i = 2; ;i++){
        if(is_prime(i))
            cout << i << endl;
        L--;
        if(L == 0)
            break;
    }
    return 0;
}

