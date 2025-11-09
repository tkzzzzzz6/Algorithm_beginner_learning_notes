#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    string target = "while";
    int cnt = 0;
    for(int i = 0; i < 5; ++i){
        if(s[i] != target[i])
            ++cnt;
    }
    cout << cnt << endl;
    return 0;
}