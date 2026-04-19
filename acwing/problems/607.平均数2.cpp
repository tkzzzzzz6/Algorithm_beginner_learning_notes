/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 14:06:46
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 14:06:50
 */
/*
* @acwing app=acwing.cn id=609 lang=C++
*
* 607. 平均数2
*/


// @acwing code start
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double a,b,c;
    cin >> a >> b >> c;

    cout << "MEDIA = " << fixed << setprecision(1) << (2*a+3*b+5*c) / 10;
    return 0;
}


// @acwing code end
