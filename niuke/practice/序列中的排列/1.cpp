#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		set<int> s;
		for (int i = 0; i < n; ++i) {
			//we can't use because it can be multi-digits-numbers
			//int x = int(getchar()-'0');
			int x;
			cin >> x;
			s.insert(x);
		}

		bool found = true;
		for (int i = 1; i <= k; ++i) {
			//if (s.find(i) == s.end()) 
			if(s.count(i) == 0){
				found = false;
				break;
			}
		}
		cout << (found ? "YES" : "NO") << endl;
	}
	return 0;
}