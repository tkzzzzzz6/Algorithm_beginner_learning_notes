#include <stdio.h>
#include <iostream>

using namespace std;

int N;
int d[10010];
char result[10010][10010];
int num = 0;

bool isLegal(int row, int col) {
	bool judge = true;
	for (int i = 1; i < row; ++i) {
		if (d[i] == col || i - d[i] == row - col || i + d[i] == row + col) {
			judge = false;
			break;
		}
	}
	return judge;
}

void searchChilds(int row) {
	if (row == N + 1) {
		++num;
		for (int i = 1; i <= N; ++i) 
			cout << result[i] << endl;
		cout << endl;
		return;
	}

	for (int col = 1; col <= N; ++col) {
		if (isLegal(row, col)) {
			d[row] = col;
			result[row][col - 1] = 'Q';
			searchChilds(row + 1);
			result[row][col - 1] = '.';
			d[row] = 0;
		}
	}
}

int main() {
	cin >> N;
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < N; ++j) {
			result[i][j] = '.';
		}
	}

	searchChilds(1);
	cout << num;

	return 0;
}