#include <bits/stdc++.h>
using namespace std;

//375 = 3 * 125 = 3 * 5^3

int main() {
	string str;
	cin >> str;
	int n = str.length();
	if (n < 3) {
		cout << -1 << endl;
		return 0;
	} // length shorter than 3 can't be div by 125
	vector<int> digits(10,0);

	//static the times that each number apper
	//for (int i = 0; i < n; ++i)
	//	digits[int(str[i])] += 1;

	for (char c : str)digits[c - '0']++;

	//judge if str can be div by 
	int sum = 0;
	for (char c : str)sum += c - '0';
	if (sum % 3 != 0) {
		cout << -1 << endl;
		return 0;
	}
	const vector<string> endings = { "000","125","250","375","500","625","750","875" };

	for (const auto& ending : endings) {
		auto temp_digits = digits;

		//check if the ending can be construct
		bool valid = true;
		for (char c : ending) {
			if (temp_digits[c - '0'] > 0)
				temp_digits[c - '0']--;
			else {
				valid = false;
				break;
			}
		}

		if (!valid)
			continue;

		//construct front partition:the digits left sort by desc
		string result;
		for (int digit = 9; digit >= 0; digit--) {
			for (int i = 0; i < temp_digits[digit]; ++i) {
				result += to_string(digit);
			}
		}

		//process front zero
		if (!result.empty() && result[0] == '0') {
			bool found = false;
			for (size_t i = 0; i < result.length(); ++i) {
				if (result[i] != '0') {
					swap(result[0], result[i]);
					found = true;
					break;
				}
			}

			if (!found) {
				continue;
			}
		}
		cout << result + ending << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;

}
// 64 Î»Êä³öÇëÓÃ printf("%lld")