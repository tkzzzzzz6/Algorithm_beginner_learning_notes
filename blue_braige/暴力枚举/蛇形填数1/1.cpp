#include <iostream>
// 偏分版本

using namespace std;

// 1 2 6 7 15 16 28
// 3 5 8 14 17 27
// 4 9 13 18 26
// 10 12 19 25
// 11 20 24
// 21 23 
// 22

// 1 5 13 25
// 1 
// 1+4
// 1+4+8
// 1+4+8+12
int main(){
    int sum = 1;
    for (int i = 1; i < 20;++i){
        sum += i * 4;
    }
    cout << sum << endl;
        return 0;
}
