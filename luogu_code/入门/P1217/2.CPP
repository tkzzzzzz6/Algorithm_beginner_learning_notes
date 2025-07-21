// 超时
#include <iostream>
#include <string>
#include <cmath>    
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i <= sqrt(n); i += 2){
        if(n % i == 0) return false;
    }
    return true;
}

bool isPalindrome(int n){
    string s = to_string(n);
    for(int i = 0; i < s.length()/2; i++){
        if(s[i] != s[s.length()-i-1]) return false;
    }
    return true;
}

int main(){
    int a,b;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        if(isPalindrome(i) && isPrime(i)){
            cout << i << endl;
        }
    }
    return 0;
}