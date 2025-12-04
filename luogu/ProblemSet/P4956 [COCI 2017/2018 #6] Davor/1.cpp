#include<iostream>

using namespace std;

int main(){
    int n,x,k;
    cin >> n;
  
    for(x = 100;x>=1;x--)
    {
        int remainder = n - 364*n;
        if(remainder > 0 && remainder % 1092 == 0)
        {
            k = remainder / 1092;
            cout << x << endl << k << endl;
        }
    }
}
