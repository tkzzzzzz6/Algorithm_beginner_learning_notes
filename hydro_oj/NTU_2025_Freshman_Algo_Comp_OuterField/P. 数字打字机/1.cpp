#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        int total = m;
        int count = 0;
        while(m--){
            int x;
            cin >> x;
            string word(x,' ');
            for(int i = 0;i<x;++i){
                int c;
                cin >> c;
                word[i] = char(c + 'A'-1);
            }
            cout << word;
            count++;
            if(count != total) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
