#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 关闭 C/C++ 流同步，提升 cin/cout 性能 :contentReference[oaicite:1]{index=1}
    cin.tie(nullptr);            // 取消 cin 与 cout 绑定，避免不必要的刷新 :contentReference[oaicite:2]{index=2}

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> mat(n);

        for (int i = 0; i < n; i++)
        {
            cin >> mat[i];
        }

        // 计算每行和每列的1的个数
        vector<int> row_ones(n, 0);
        vector<int> col_ones(m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == '1')
                {
                    row_ones[i]++;
                    col_ones[j]++;
                }
            }
        }

        // 检查是否可以通过翻转两行得到全0矩阵
        bool two_rows_ok = false;

        // 两行全1，其余全0 => 翻转这两行可得全0
        vector<int> full_rows;
        for (int i = 0; i < n; i++)
        {
            if (row_ones[i] == m)
            {
                full_rows.push_back(i);
            }
        }

        if (full_rows.size() == 2)
        {
            bool others_zero = true;
            for (int i = 0; i < n; i++)
            {
                if (i != full_rows[0] && i != full_rows[1] && row_ones[i] > 0)
                {
                    others_zero = false;
                    break;
                }
            }
            if (others_zero)
                two_rows_ok = true;
        }

        // 检查是否可以通过翻转两列得到全0矩阵
        bool two_cols_ok = false;

        // 两列全1，其余全0 => 翻转这两列可得全0
        vector<int> full_cols;
        for (int j = 0; j < m; j++)
        {
            if (col_ones[j] == n)
            {
                full_cols.push_back(j);
            }
        }

        if (full_cols.size() == 2)
        {
            bool others_zero = true;
            for (int j = 0; j < m; j++)
            {
                if (j != full_cols[0] && j != full_cols[1] && col_ones[j] > 0)
                {
                    others_zero = false;
                    break;
                }
            }
            if (others_zero)
                two_cols_ok = true;
        }

        // 检查是否可以通过翻转一行一列得到全0矩阵
        bool row_col_ok = false;

        // 必要条件：找一个格子(r,c)是0，同时：
        // 1. 第r行除(r,c)外都是1
        // 2. 第c列除(r,c)外都是1
        // 3. 其他位置都是0
        for (int r = 0; r < n && !row_col_ok; r++)
        {
            for (int c = 0; c < m && !row_col_ok; c++)
            {
                // 如果交点不是0，跳过
                if (mat[r][c] != '0')
                    continue;

                // 检查第r行是否除了(r,c)外都是1
                if (row_ones[r] != m - 1)
                    continue;

                // 检查第c列是否除了(r,c)外都是1
                if (col_ones[c] != n - 1)
                    continue;

                // 检查其他位置是否都是0
                bool other_positions_zero = true;

                for (int i = 0; i < n && other_positions_zero; i++)
                {
                    for (int j = 0; j < m && other_positions_zero; j++)
                    {
                        // 跳过第r行和第c列
                        if (i == r || j == c)
                            continue;

                        if (mat[i][j] == '1')
                        {
                            other_positions_zero = false;
                            break;
                        }
                    }
                }

                if (other_positions_zero)
                {
                    row_col_ok = true;
                }
            }
        }

        // 任一方式可行即可
        if (two_rows_ok || two_cols_ok || row_col_ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
