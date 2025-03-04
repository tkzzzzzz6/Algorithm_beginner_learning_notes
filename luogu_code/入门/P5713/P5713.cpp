#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n*5 < 11+3*n){
        cout << "Local";
    }else{
        cout << "Luogu";
    }
}