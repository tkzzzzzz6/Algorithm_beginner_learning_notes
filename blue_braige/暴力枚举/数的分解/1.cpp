#include <iostream>
#include <vector>

using namespace std;

bool check(int x) {
    while (x) {
        if (x % 10 == 2 || x % 10 == 4) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main() {
    int res = 0;
    int num = 2019;
    vector<int> validNumbers;

    // Precompute valid numbers
    for (int i = 1; i < num; ++i) {
        if (check(i)) {
            validNumbers.push_back(i);
        }
    }

    // Use three nested loops to find combinations
    for (size_t i = 0; i < validNumbers.size(); ++i) {
        for (size_t j = i + 1; j < validNumbers.size(); ++j) {
            for (size_t k = j + 1; k < validNumbers.size(); ++k) {
                if (validNumbers[i] + validNumbers[j] + validNumbers[k] == num) {
                    res++;
                }
            }
        }
    }
    
    cout << res << endl;
    return 0;
}