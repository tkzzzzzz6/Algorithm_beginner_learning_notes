#include <iostream>
#include <string>

using namespace std;

string unzip(){
    string str1 ="",x ="";
    char c;
    int num;
    while(cin >> c){
        if(c == '['){
            cin >> num;
            x = unzip();
            while(num--){
                str1 += x;
            }
        }
        else if(c == ']'){
            return str1;
        }
        else{
            str1 += c;
        }
    }
    return str1;
}

int main(){
    cout << unzip();
    return 0;
}