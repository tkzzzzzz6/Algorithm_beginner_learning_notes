//基于模运算的校验码
#include <iostream>
#define mod 11

using namespace std;

int clac_checksum(int *arr, int len){
    int weights[] = {6,5,4,3,2,1};
    int sum = 0;

    for(int i = 0; i < len; i++){
        sum += arr[i] * weights[i];
    }

    return sum % mod;
}

int main(){
    int data[6] = {1,2,3,4,10,6};
    int len = sizeof(data) / sizeof(data[0]);
    int checksum = clac_checksum(data, len);

    cout << "checksum: " << checksum << endl;

}


