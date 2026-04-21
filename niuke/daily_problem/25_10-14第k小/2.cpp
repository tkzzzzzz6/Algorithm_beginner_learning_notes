#include <bits/stdc++.h>
//гʱ

using namespace std;

//operation1 add element
void manipulate1(priority_queue<int>& pq,int k) {
	int num;
	cin >> num;

	if (pq.size() < k) {
		pq.push(num);
	}
	else if (num < pq.top()) {
		pq.pop();
		pq.push(num);
	}
}

void manipulate2(priority_queue<int> pq, int k) {
	if (pq.size() < k)cout << -1 << endl;
	else cout << pq.top() << endl;//ѶǵkС
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	priority_queue<int> pq; // ,Ѷֵ

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;

		if (pq.size() < k) {
			pq.push(num);//δ,ֱӼ
		}
		else if (num < pq.top()) {//ȶѶС
			pq.pop();//
			pq.push(num);
		}
	}

	//process m times operations
	while (m--) {
		int opr1;
		cin >> opr1;

		if (opr1 == 1)manipulate1(pq, k);
		else manipulate2(pq, k);
	}
	return 0;
}
