#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a_cnt = 0;
    bool ok = true;
    for(char c:s){
        if(c == 'a')++a_cnt;
        else{
            if(a_cnt == 0){
                ok = false;
                break;
            }else{
                --a_cnt;
            }
        }
    }
    ok = ok && (a_cnt == 0);
    cout << (ok ? "Good" : "Bad") << endl;
}
