/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 13:55:46
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 13:55:48
 */
/*
* @acwing app=acwing.cn id=606 lang=C++
*
* 604. 圆的面积
*/

// @acwing code start

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    const double PI = 3.14159;
    double r;cin >> r;
    double res = PI*r*r;
    cout << "A=" << fixed <<  setprecision(4) << res <<'\n';
    return 0;
}

// @acwing code end
