/*
* @acwing app=acwing.cn id=613 lang=C++
*
* 611. 简单计算
*/

// @acwing code start

#include <iostream>
#include <iomanip>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<int,double> price;
    int i = 2;
    while(i--){
        int id;        int amount;
        double p;
        cin >> id >> amount;
        cin >> p;
        price[id] = amount*p;
    }

    double res = 0;
    for(auto &kv : price){
        res += kv.second;
    }

    cout << "VALOR A PAGAR: R$ "  << fixed << setprecision(2) << res << endl;
    return 0;
}


// @acwing code end
