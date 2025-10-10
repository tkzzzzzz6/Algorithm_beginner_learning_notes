#include <bits/stdc++.h>

using namespace std;

// 求最大公约数
// a,b的最小公倍数等于ab的乘积除以ab的最小公因子
int gcd(int a,int b){
    if(b == 0)return a;
    else
        return gcd(b, a % b);
}


int LCM(int a,int b){
    return a * b /gcd(a,b);
}
int main(){
    int a = 2009, b = 1394;
    cout << LCM(a,b) << endl;
    return 0;
}