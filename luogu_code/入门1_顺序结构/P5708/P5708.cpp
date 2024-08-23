#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a,b,c;
    cin >> a >> b >> c;
    double p = (a+b+c)/2;
    double s = std::sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.1f",s);
}