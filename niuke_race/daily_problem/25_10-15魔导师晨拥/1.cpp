#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int damage = 2;
	int damage2hero = 0;
	for (int i = 0; i < n; ++i)cin >> a[i];
	while(m--){
		for (int i = 0; i < n; ++i) {
			a[i] -= damage;
			if (a[i] == 0)damage++;
		}
		damage2hero += damage;
	}
	cout << damage2hero << endl;
}
