#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    int n = 100;
    int u = 3;
    int d = 2;
    int i = 0;
    int cnt = 0;
    while(i >= n){
        i += u;
        cnt++;
        i -= d;
    }
    cout << cnt << endl;
}
