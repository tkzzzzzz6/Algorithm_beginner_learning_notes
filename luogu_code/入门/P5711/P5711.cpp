#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n % 4 == 0 && n % 100 != 0)
        cout << 1 << endl;
    else if (n % 400 == 0 )
            cout << 1 << endl;
    else cout << 0 << endl;
}