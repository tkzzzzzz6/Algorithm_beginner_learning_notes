#include <iostream>

using namespace std;

int binary_search(int arr[],int value,int low,int high){
    int mid = (low + high) / 2;
    if(low > high)
        return -1;
    if (arr[mid] == value)
        return mid;
    if(arr[mid] > value)
        return binary_search(arr,value,low,mid - 1);
    else
        return binary_search(arr,value,mid + 1,high);
}

int main(){
    int arr[2][3];
    int *p = &arr[0][0];
    for (int i = 1; i < 7;i++,p++)
        *p = 2 * i;
    int index = binary_search(&arr[0][0], 8, 0, sizeof(arr) / sizeof(arr[0][0]));
    cout << arr[index / 3][index % 3] << endl;
    cout << index / 3 << endl;
    cout << index % 3 << endl;
    return 0;
}

