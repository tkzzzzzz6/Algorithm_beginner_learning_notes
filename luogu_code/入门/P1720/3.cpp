#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculate(int n){
    double n1 = (1+sqrt(5))/2;
    double n2 = (1-sqrt(5))/2;
    double sum1 = 1;
    double sum2 = 1;
    for(int i = 1; i <= n; i++){
        sum1 *= n1;
        sum2 *= n2;
    }   
    return (sum1 - sum2)/sqrt(5);
}

int main(){
    int n;
    cin >> n;
    cout << setprecision(2) << fixed << calculate(n);
    return 0;
}