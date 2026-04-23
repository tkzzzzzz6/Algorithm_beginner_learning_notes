/*
* @acwing app=acwing.cn id=615 lang=C++
*
* 613. 面积
*/

// @acwing code start

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double a,b,c;cin >> a >> b >> c;
    const double PI = 3.14159;
    cout << fixed << setprecision(3);
    cout << "TRIANGULO: " << 1 / 2.0 * a * c << endl;
    cout << "CIRCULO: " << PI * c * c << endl;
    cout << "TRAPEZIO: " << 1 / 2.0 * (a + b) * c << endl;
    cout << "QUADRADO: " << b * b << endl;
    cout << "RETANGULO: " << a * b << endl;
    return 0;
}

// @acwing code end
