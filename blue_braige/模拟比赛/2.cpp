#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=0,a = 0,b = 0;
    cin >> n;
    char vote;
    while (n--) {
        cin >> vote;
        if(vote == 'A') {
            a++;
        }else{
            b++;
        }
    }
    if(a > b) {
        cout << "A";
    }else{
        cout << "B";
    }

    return 0;    
}
