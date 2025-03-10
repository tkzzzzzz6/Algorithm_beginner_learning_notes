#include <iostream>

using namespace std;

double feibolaqi(int n){
    if (n == 1 || n == 2){
        return 1;
    }
    return feibolaqi(n-1) + feibolaqi(n-2);
}

int main(){

    int n;
    cin >> n;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << double(feibolaqi(n));

}
