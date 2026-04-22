/*
* @acwing app=acwing.cn id=612 lang=C++
*
* 610. 工资和奖金
*/

// @acwing code start

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    string name;
    cin >> name;

    double base_salary;
    cin >> base_salary;

    double sell;
    cin >> sell;

    cout << "TOTAL = R$ " <<fixed << setprecision(2) <<  base_salary + sell * 0.15;
    return 0;
}


// @acwing code end
