#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>

using namespace std;

// method 1
// bool judge_prime(int a) {
//	if (a <= 1)return false;
//	if (a == 2)return true;
//	if (a % 2 == 0)return false;
//	for (int i = 3; i * i <= a; ++i) {
//		if (a % i == 0)return false;
//	}
//	return true;
// }
//
// bool judge_palindrome(int a) {
//	vector<int> digits;
//	while (a != 0) {
//		digits.push_back(a % 10);
//		a /= 10;
//	}
//	auto front = digits.begin();
//	auto back = digits.end()-1;
//	while (front < back) {
//		if (*front != *back)return false;
//		++front;
//		--back;
//	}
//	return true;
// }
//
// int main() {
//	int n, m;
//	cin >> n >> m;
//	int cnt = 0;
//	for (int i = n; i <= m; ++i) {
//		if (judge_prime(i) && judge_palindrome(i)) {
//			cnt++;
//			cout << i << ' ';
//			if (cnt % 10 == 0)cout << endl;
//		}
//	}
//	return 0;
// }

// method 2 improved
int n, m;
int main()
{
    cin >> n >> m;
    int cnt = 0;
    for (int i = n; i <= m; ++i)
    {
        int front = i, back = 0;
        while (front > 0)
        {
            back = front % 10 + back * 10;
            front /= 10;
        }
        if (i == back)
        {
            bool flag = true;
            for (int j = 2; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ++cnt;
                cout << i << ' ';
                if (cnt % 10 == 0)
                    cout << endl;
            }
        }
    }

    return 0;
}