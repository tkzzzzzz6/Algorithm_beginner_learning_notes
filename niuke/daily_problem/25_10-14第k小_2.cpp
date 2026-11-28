#include <bits/stdc++.h>
//运行超时

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
	else cout << pq.top() << endl;//堆顶就是第k小的数
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	priority_queue<int> pq; // 最大堆,堆顶是最大值

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;

		if (pq.size() < k) {
			pq.push(num);//堆未满,直接加入
		}
		else if (num < pq.top()) {//新数比堆顶小
			pq.pop();//弹出最大的
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