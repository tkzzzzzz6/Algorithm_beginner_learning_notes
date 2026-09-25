/*
* @acwing app=acwing.cn id=3711 lang=C++
*
* 3708. 求矩阵的鞍点
*/

// @acwing code start
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n = 15;
vector<vector<int>> mat(n,vector<int>(15));

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> rowmax(n,0); 
    vector<int> colmin(m, INT_MAX);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
            rowmax[i] = max(rowmax[i], mat[i][j]);
            colmin[j] = min(colmin[j], mat[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == rowmax[i] && mat[i][j] == colmin[j]) {
                cout << i+1 << ' ' << j+1 << ' '<< mat[i][j] << '\n';
                cnt++;
            }
        }
    }

    if (cnt == 0) {
        cout << "NO\n ";
    }

    return 0;
}

// @acwing code end