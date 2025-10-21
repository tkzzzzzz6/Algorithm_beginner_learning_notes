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

vector<int64_t> division(int64_t a,int64_t b){
    vector<int64_t> result(2);
    result[0] = a/b;
    result[1] = a%b;
    return result;
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
                vector<int64_t> result = division(num1,num2);
                cout << result[0] << " " << result[1] << endl;
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
