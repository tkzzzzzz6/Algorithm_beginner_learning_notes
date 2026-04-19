/*
* @acwing app=acwing.cn id=608 lang=C++
*
* 606. 平均数1
*/

// @acwing code start
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double a,b;
    cin >> a >> b;

    cout << "MEDIA = " << fixed << setprecision(5) << (3.5*a+7.5*b) / 11;
    return 0;
}


// @acwing code end
