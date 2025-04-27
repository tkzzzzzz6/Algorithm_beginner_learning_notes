#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 检查矩阵是否全为0
bool isAllZero(const vector<vector<char>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (char cell : row)
        {
            if (cell == '1')
                return false;
        }
    }
    return true;
}

// 复制矩阵
vector<vector<char>> copyMatrix(const vector<string> &original)
{
    int n = original.size();
    int m = original[0].size();
    vector<vector<char>> copy(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            copy[i][j] = original[i][j];
        }
    }
    return copy;
}

// 翻转一行
void flipRow(vector<vector<char>> &matrix, int row)
{
    for (int j = 0; j < matrix[0].size(); ++j)
    {
        matrix[row][j] = (matrix[row][j] == '0') ? '1' : '0';
    }
}

// 翻转一列
void flipColumn(vector<vector<char>> &matrix, int col)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        matrix[i][col] = (matrix[i][col] == '0') ? '1' : '0';
    }
}

// 使用奇偶性优化的两行翻转检查
bool checkTwoRowsOptimized(const vector<string> &matrix)
{
    int n = matrix.size();
    if (n <= 1)
        return false;

    // 检查所有行的1的个数奇偶性是否相同
    int parity = -1;
    for (int i = 0; i < n; ++i)
    {
        int count = 0;
        for (char c : matrix[i])
        {
            if (c == '1')
                count++;
        }

        if (parity == -1)
        {
            parity = count % 2;
        }
        else if (parity != count % 2)
        {
            return false;
        }
    }
    return true;
}

// 检查模式2：翻转两列
bool checkTwoColumns(const vector<string> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // 尝试所有可能的两列组合
    for (int c1 = 0; c1 < m; ++c1)
    {
        for (int c2 = 0; c2 < m; ++c2)
        { // 注意：c1可以等于c2，表示同一列翻转两次
            auto copy = copyMatrix(matrix);
            flipColumn(copy, c1);
            flipColumn(copy, c2);
            if (isAllZero(copy))
                return true;
        }
    }
    return false;
}

// 检查模式3：翻转一行一列
bool checkOneRowOneColumn(const vector<string> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // 尝试所有可能的行列组合
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            auto copy = copyMatrix(matrix);
            flipRow(copy, r);
            flipColumn(copy, c);
            if (isAllZero(copy))
                return true;
        }
    }
    return false;
}

// 改进版的一行一列检查
bool checkOneRowOneColumnOptimized(const vector<string> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // 特殊情况：如果只有一个1，肯定不能通过一行一列翻转得到全0
    int totalOnes = 0;
    for (const auto &row : matrix)
    {
        for (char c : row)
        {
            if (c == '1')
                totalOnes++;
        }
    }

    if (totalOnes == 1)
        return false;
    if (totalOnes == 0)
        return true;

    // 普通情况继续暴力检查
    return checkOneRowOneColumn(matrix);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> matrix(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> matrix[i];
        }

        // 检查三种模式
        bool canMakeAllZero = checkTwoRowsOptimized(matrix) || checkTwoColumns(matrix) || checkOneRowOneColumnOptimized(matrix);

        cout << (canMakeAllZero ? "YES" : "NO") << endl;
    }
    return 0;
}
