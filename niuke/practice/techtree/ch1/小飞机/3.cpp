#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout.setf(ios::fixed);

    vector<string> matrix = {
        "**",
        "**",
        "************",
        "************",
        "*  *",
        "*  *"};

    int width = 12; // 每行宽度
    for (int i = 0; i < matrix.size(); ++i)
    {
        int len = matrix[i].length();
        int leftPad = (width - len) / 2; // 左边填充空格数

        // 使用 setw 和 setfill 控制输出
        cout << setfill(' ') << setw(leftPad + len) << right << matrix[i]
             << setw(width - leftPad - len) << "" << '\n';
    }

    return 0;
}