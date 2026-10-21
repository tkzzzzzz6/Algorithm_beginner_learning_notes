#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 定义每个数字的3x5点阵表示
    vector<string> d[10] = {
        {"XXX", "X.X", "X.X", "X.X", "XXX"}, // 0
        {"..X", "..X", "..X", "..X", "..X"}, // 1
        {"XXX", "..X", "XXX", "X..", "XXX"}, // 2
        {"XXX", "..X", "XXX", "..X", "XXX"}, // 3
        {"X.X", "X.X", "XXX", "..X", "..X"}, // 4
        {"XXX", "X..", "XXX", "..X", "XXX"}, // 5
        {"XXX", "X..", "XXX", "X.X", "XXX"}, // 6
        {"XXX", "..X", "..X", "..X", "..X"}, // 7
        {"XXX", "X.X", "XXX", "X.X", "XXX"}, // 8
        {"XXX", "X.X", "XXX", "..X", "XXX"}, // 9
    };

    int n;
    string num;
    cin >> n >> num;

    for (int row = 0; row < 5; ++row) {
        for (int i = 0;i<n;++i){
            if (i > 0) cout << '.';
            cout << d[num[i] - '0'][row];
        }
        cout << '\n';
    }

    return 0;
}

