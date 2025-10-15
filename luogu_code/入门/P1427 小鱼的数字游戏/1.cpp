#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    stack<int> s;
    int i = 0;
    do{
        cin >> i;
        s.push(i);
    } while (i != 0);

    s.pop();

    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}