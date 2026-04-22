/*
* @acwing app=acwing.cn id=611 lang=C++
*
* 609. 工资
*/

// @acwing code start
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int id,worktime;
    cin >> id >> worktime;
    double money;
    cin >> money;

    cout << "NUMBER = " << id << endl;
    cout << "SALARY = U$ " << fixed << setprecision(2) << worktime * money << endl;
    return 0;
}


// @acwing code end
