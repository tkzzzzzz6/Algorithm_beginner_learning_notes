// Nowcoder Compiler: C++（clang++18）
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b,c;
    cin >> a >> b >> c;

    if(a+b < c || a + c < b || b + c < a){
        cout << "Not a triangle\n";
    }else if(a == b && a == c && b == c){
        cout << "Equilateral\n";
    }else if(a == b || a == c || b == c){
        cout << "Isosceles\n";
    }else{
        cout << "Scalene\n";
    }

    
    return 0;
}
