#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> a(3);
    while(t--){
        for(int i = 0; i < 3; i++){
            cin >> a[i];
        }
        double step = abs(double(a[1])/a[2]);
        // printf("%.3f\n",step);
        if(a[1] == 0){
            cout << 0 << endl;
        }else if(step > a[0]){
            cout << -1 << endl;
        }else{
            cout << ceil(step) << endl;
        }

    }
}
