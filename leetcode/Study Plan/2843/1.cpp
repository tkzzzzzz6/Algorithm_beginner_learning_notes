#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSymmetricNumber(int num) {
        if (num < 0) return false;  // 处理负数
        if (num == 0) return true;  // 处理0

        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        // 如果数字位数为奇数，直接返回false
        if (digits.size() % 2 != 0) return false;

        int left = 0, right = digits.size() - 1;
        int sum = 0;

        while (left < right) {
            sum += digits[left] - digits[right];
            left++;
            right--;
        }

        return sum == 0;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++i) {
            if (isSymmetricNumber(i)) count++;
        }
        return count;
    }
};

int main() {
    Solution s;
    int low, high;
    cin >> low >> high;
    cout << s.countSymmetricIntegers(low, high) << endl;
    return 0;
}