
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void flip(vector<int>& arr, int k) {
    reverse(arr.begin(), arr.begin() + k);
}

int pancakeSort(vector<int>& arr) {
    int n = arr.size();
    int count = 0;

    for (int currSize = n; currSize > 1; currSize--) {
        int maxidx = 0;
        for (int i = 1; i < currSize; ++i) {
            if (arr[i] > arr[maxidx])maxidx = i;
        }
        
        if (maxidx == currSize - 1)continue;

        if (maxidx > 0) {
            flip(arr, maxidx + 1);
            count++;
        }

        flip(arr, currSize);
        count++;
    }

    return count;

}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;

    vector<int> redius(n);
    for (int i = 0; i < n; i++)cin >> redius[i];
   
    cout << pancakeSort(redius) << '\n';

    return 0;
}