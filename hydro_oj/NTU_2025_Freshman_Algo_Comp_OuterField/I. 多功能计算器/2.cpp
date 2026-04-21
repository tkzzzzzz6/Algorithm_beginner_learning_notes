#include <bits/stdc++.h>
using namespace std;

long long add(long long a,long long b){
    return a+b;
}

long long mul(long long a,long long b){
    return a*b;
}

long long sub(long long a,long long b){
    return a-b;
}

pair<long long,long long> division(long long a,long long b){
    return {a/b, a%b};
}

int main() {
    int n;
    cin >> n;
    cin.ignore();  // Ignore the newline character after the integer input
    while(n--){
        string line;
        getline(cin,line);
        stringstream ss(line);
        int num1,num2;
        char op;
        ss >> num1 >> op >> num2;
        switch(op){
            case '+':
                cout << add(num1,num2) << endl;
                break;
            case '-':
                cout << sub(num1,num2) << endl;
                break;
            case '*':
                cout << mul(num1,num2) << endl;
                break;
            case '/':{
                pair<int,int> result = division(num1,num2);
                cout << result.first << " " << result.second << endl;
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
