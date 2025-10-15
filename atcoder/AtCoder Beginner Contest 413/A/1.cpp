#include <iostream>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    int sum = 0,a = 0;
    for (int i = 0; i < n;++i){
        cin >> a;
        sum += a;
    }
    if(sum <= m)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}