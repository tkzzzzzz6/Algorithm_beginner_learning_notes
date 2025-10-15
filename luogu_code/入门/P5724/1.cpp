#include <iostream>

using namespace std;

int main(){
    int n,max,min;
    cin >> n;
    cin >> max;
    cin >> min;
    min = max > min ? min : max;
    for(int i = 0; i < n-1; i++){
        int a;
        cin >> a;
        if(a > max){
            max = a;
        }
        if(a < min){
            min = a;
        }
    }
    cout << max - min;
    return 0;
}