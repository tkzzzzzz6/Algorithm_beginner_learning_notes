#include <bits/stdc++.h>

using namespace std;

int main(){
    int k,now = 0;
    cin >> k;
    // 1,2,2,3,3,3
    long long sum = 0;
    for(int i = 1; i <= k; i++){
        now += 1;
        while(now--){
            sum += i;
        }
        k -= now;
    }
    cout << sum;
    return 0;
}
