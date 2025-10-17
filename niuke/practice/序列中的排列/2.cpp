#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		vector<int> a(101);
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			a[x]++;
		}
		for (int i = 1; i <= k; ++i) {
			if (a[i] == 0) {
				cout << "NO" << endl;
				goto end;
			}
		}
		cout << "YES" << endl;
		end:;
	}
	return 0;
}