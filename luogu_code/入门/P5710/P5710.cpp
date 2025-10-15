#include <iostream>

using namespace std;

int main(){
    int x, a, b, n1, n2, n3, n4;
    cin >> x;
    a = b = 0;
    n1 = n2 = n3 = n4 = 0;

    if (x % 2 == 0){
        a = 1;
    }

    if (x > 4 && x <= 12){
        b = 1;
    }

    if (a == 1 && b == 1){
        n1 = 1;
    }

    if (a == 1 || b == 1){
        n2 = 1;
    }

    if ((a == 1 && b == 0) || (a == 0 && b == 1)){
        n3 = 1;
    }

    if (a == 0 && b == 0){
        n4 = 1;
    }

    cout << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
}