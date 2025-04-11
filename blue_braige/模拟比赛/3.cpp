#include <bits/stdc++.h>

using namespace std;

int sum = 0;
int n,m;
int matrix[100][26];

void add(int row,int col) {
    sum += matrix[row][col];
}


// A - 65
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    string formula;
    cin >> formula;
    int col,row;
    for(int i = 1; i < formula.length(); i++) {
        if( formula[i] >= 'A'&& formula[i] <= 'Z'){
            col = formula[i]-'A';
            row = formula[++i]-'1';
            add(row,col);
        }
    }
    cout << sum << endl;    
    return 0;
}
