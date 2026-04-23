/*
* @acwing app=acwing.cn id=616 lang=C++
*
* 614. 最大值
*/

// @acwing code start

#include <iostream>
#include <cmath>

using namespace std;

int intMax(int a,int b){
    return ((a+b)+abs(a-b))/2;
}

int intMin(int a,int b){
    return ((a+b)-abs(a-b))/2;
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout <<  intMax(intMax(a,b),c) << " eh o maior" << endl;
    return 0;
}


// @acwing code end
