#include <iostream>
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;

    // A && B 
    char and_result;
    if (a == 'F' || b == 'F') {
        and_result = 'F';
    } else if (a == 'T' && b == 'T') {
        and_result = 'T';
    } else {
        and_result = '0';
    }

    // A || B 
    char or_result;
    if (a == 'T' || b == 'T') {
        or_result = 'T';
    } else if (a == 'F' && b == 'F') {
        or_result = 'F';
    } else {
        or_result = '0';
    }

    cout << and_result << " " << or_result << endl;

    return 0;
}