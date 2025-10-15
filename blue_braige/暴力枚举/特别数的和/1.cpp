#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n;++i){
        int j = i;
        while(j){
            if(j % 10 == 2 || j % 10 == 0 || j % 10 == 1 || j % 10 == 9){
                sum += i;
                break;
            }
            j /= 10;
        }
    }
    cout << sum << endl;
    return 0;
}