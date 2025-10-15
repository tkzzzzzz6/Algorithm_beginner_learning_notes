#include <iostream>
#include <vector>

using namespace std;

int countOccurrences(vector<int> arr, int x)
{
    // Write your code here.
    int count = 0;
    for (int i = 0; i < arr.size();++i){
        if(arr[i] == x){    
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int x = 3;
    cout << countOccurrences(arr, x) << endl;
    return 0;
}