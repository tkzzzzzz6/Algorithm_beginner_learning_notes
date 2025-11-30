#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector <int>> trangle(n);
    for(int i = 0;i<n;++i)
    {
        trangle[i].resize(i+1);
        trangle[i][0] = 1;
        trangle[i][i] = 1;
        for(int j = 1;j<i;++j)
        {
            trangle[i][j] = trangle[i-1][j-1] + trangle[i-1][j];
        }
    }
    for(int i = 0;i<n;++i)
    {
        for(int j = 0;j<trangle[i].size();++j)
        {
            cout << trangle[i][j] << (j == trangle[i].size()-1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
