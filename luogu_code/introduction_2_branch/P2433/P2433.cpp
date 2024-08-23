#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        cout << 14 / 4 << endl << 14 - 14 % 4 << endl << 14 % 4;
    } else if (T == 4) {
        cout << fixed << setprecision(3) <<500.0 /3 << endl;
    } else if (T == 5) {
        cout << (260 + 220) / (12 + 20)<< endl;
    } else if (T == 6) {
        cout << sqrt(6 * 6 + 9 * 9) << endl;
    } else if (T == 7) {
        int account_balance = 100;
        int save_money = account_balance+10;
        cout << save_money << endl;
        int use_money = save_money - 20;
        cout << use_money << endl;
        cout << 0 << endl;
    } else if (T == 8) {
        double pi = 3.141593;
        int r = 5;
        cout << 2*pi*r << endl;
        cout << pi*r*r << endl;
        cout << 4.0/3*pi*r*r*r << endl;
    } else if (T == 9) {
        int remain = 1;
        for (int i = 1; i <= 4; i++) {
            remain = (remain ) * 2+1;
        }
        cout << remain << endl;
    } else if (T == 10) {
        cout << 9 << endl;
    } else if (T == 11) {
        cout << 100.0 / 3 << endl;
    } else if (T == 12) {
        cout << 'M'-'A'+1 << endl;
        cout << (char)('A'+17) << endl;
    } else if (T == 13) {
        double PI = 3.141593;
        double volume = 4.0/3*PI*14*14*14;
        double prism;
        prism = pow(volume,1.0/3);
        cout << int(prism) <<endl;
    } else if (T == 14) {
        double a = -1,b=100,c=-2400;
        double discriminant = b*b-4*a*c;

        if (discriminant > 0) {
            double x1 = (-b+sqrt(discriminant))/(2*a);
            double x2 = (-b-sqrt(discriminant))/(2*a);
            if (x1 > x2) {
                cout << int(x2) << endl;
            } else {
                cout << int(x1) << endl;
            }
        } else if (discriminant == 0) {
            double x = -b/(2*a);
            cout << int(x) << endl;
        } else {
            cout << "No answer" << endl;
        }
    }
    return 0;
}