// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    string answer;
    for (int i = 0; i < n - 2; ++i) {
        answer += "1 ";
    }

    answer += "2 " + to_string(n) + '\n';
    cout << answer;

    return 0;
}
