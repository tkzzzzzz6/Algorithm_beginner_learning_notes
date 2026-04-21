#include <iostream>
using namespace std;

int main() {
    long long a = 1, b = 1;
    int n = 2;

    while (b <= 20211001) {
        long long temp = a + b;
        a = b;
        b = temp;
        ++n;
        if(b > 20211001){
            cout << b;
            break;
        }
    }

    cout << n << endl;
    return 0;
}
