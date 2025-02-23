#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;

    string s;
    for (int i = 0; i < N; i++){
        s += 'A' + i;
    }
    for(int j = 0; j < Q; j++){
        if(j == N)break;
        cout <<"?"<<" "<< s[j] <<" "<< s[j+1] << endl;
        char ans;
        cin >> ans;
        if (ans=='>')swap(s[j], s[j+1]);
    }
    cout <<"!"<<" ";
    for (int i = 0; i < N; i++){
        cout << s[i];
    }
    return 0;
}
