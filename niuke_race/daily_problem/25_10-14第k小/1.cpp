#include <bits/stdc++.h>
//‘À––≥¨ ±

using namespace std;

void manipulate1(vector<int> &a) {
	int x;
	cin >> x;
	a.emplace_back(x);
}

//bool compare(int a, int b) {
//	return abs(a) < abs(b);
//}

int manipulate2(vector<int> a,int k) {
	if (k > a.size())
		return -1;
	//sort(a.begin(), a.end(), [](int a, int b) {return a < b; });
	//return a[k - 1];
	nth_element(a.begin(), a.begin() + k - 1, a.end());
	return a[k - 1];
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	int i = 0;
	while (n--) {
		cin >> a[i];
		i++;
	}
	int operator1 = 0;
	while (m--) {
		cin >> operator1;
		if (operator1 == 1) manipulate1(a);
		else cout << manipulate2(a, k) << endl;
	}
	return 0;
}