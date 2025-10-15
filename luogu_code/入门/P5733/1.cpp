#include <iostream>
#include <vector>

using namespace std;

int main(){

    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i]>='a' && str[i]<='z' )str[i]+='A'-'a';
    }
    cout << str;
    return 0;
}