#include <iostream>
using namespace std;
int main(){
    int n,a,b,c;
    int cnt = 0;
    cin>>n>>a>>b>>c;
    while(n>=a){
        cnt++;
        n -= a;
    }
    while(n>=b){
        cnt++;
        n -= b;
    }
    while(n>=c){
        cnt++;
        n -= c;
    }
    cout<<cnt<<endl;

}