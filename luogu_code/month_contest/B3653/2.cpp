#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 读取输入并存储地鼠的分数
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    // 初始化答案数组
    vector<vector<int>> ans(n, vector<int>(m, 0));

    // 计算每个位置的最远亲戚距离
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (b[i][j] == b[x][y]) {
                        int distance = (i - x) * (i - x) + (j - y) * (j - y);
                        ans[i][j] = max(ans[i][j], distance);
                    }
                }
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
