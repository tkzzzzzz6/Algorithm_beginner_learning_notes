#include <iostream>
#include <map>

typedef long long LL;

using namespace std;

LL a[200001];
map<LL, LL> m;


int main() {
	int n;
	LL ans = 0;
	LL c;
	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++m[a[i]];
		a[i] = a[i] - c;
	}
	for (int i = 0; i < n; ++i) {
		ans += m[a[i]];
	}
	cout << ans << endl;
	return 0;
}

