/*
 * 矩阵快速幂 (Matrix Exponentiation)
 * 用途：快速计算矩阵的幂，加速递推关系求解（如斐波那契数列）
 * 时间复杂度：O(n^3 * log k)，n为矩阵大小，k为指数
 * 空间复杂度：O(n^2)
 */

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

class Matrix {
public:
    int n, m;
    vector<vector<long long>> mat;

    Matrix(int rows, int cols) : n(rows), m(cols) {
        mat.assign(n, vector<long long>(m, 0));
    }

    // 单位矩阵
    static Matrix identity(int size) {
        Matrix I(size, size);
        for (int i = 0; i < size; i++) {
            I.mat[i][i] = 1;
        }
        return I;
    }

    // 矩阵乘法
    Matrix operator*(const Matrix& other) const {
        Matrix result(n, other.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < other.m; j++) {
                for (int k = 0; k < m; k++) {
                    result.mat[i][j] = (result.mat[i][j] +
                                       mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    // 矩阵加法
    Matrix operator+(const Matrix& other) const {
        Matrix result(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result.mat[i][j] = (mat[i][j] + other.mat[i][j]) % MOD;
            }
        }
        return result;
    }

    // 打印矩阵
    void print() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// 矩阵快速幂
Matrix matrixPower(Matrix base, long long exp) {
    int n = base.n;
    Matrix result = Matrix::identity(n);

    while (exp > 0) {
        if (exp & 1) {
            result = result * base;
        }
        base = base * base;
        exp >>= 1;
    }

    return result;
}

// 应用1：快速计算斐波那契数列第n项
// F(n) = F(n-1) + F(n-2)
// [F(n)  ] = [1 1] * [F(n-1)]
// [F(n-1)]   [1 0]   [F(n-2)]
long long fibonacci(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    Matrix base(2, 2);
    base.mat[0][0] = 1; base.mat[0][1] = 1;
    base.mat[1][0] = 1; base.mat[1][1] = 0;

    Matrix result = matrixPower(base, n - 1);
    return result.mat[0][0];
}

// 应用2：求递推关系 a[n] = c1*a[n-1] + c2*a[n-2] + ... + ck*a[n-k]
// 的第n项
class LinearRecurrence {
private:
    vector<long long> coeffs;  // 系数 c1, c2, ..., ck
    vector<long long> initial; // 初始值 a[0], a[1], ..., a[k-1]
    int k;

public:
    LinearRecurrence(vector<long long> c, vector<long long> init)
        : coeffs(c), initial(init), k(c.size()) {}

    long long getNth(long long n) {
        if (n < k) return initial[n];

        // 构造转移矩阵
        Matrix trans(k, k);
        for (int i = 0; i < k; i++) {
            trans.mat[0][i] = coeffs[i];
        }
        for (int i = 1; i < k; i++) {
            trans.mat[i][i-1] = 1;
        }

        Matrix result = matrixPower(trans, n - k + 1);

        // 计算结果
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            ans = (ans + result.mat[0][i] * initial[k - 1 - i]) % MOD;
        }

        return ans;
    }
};

// 应用3：计算图的路径数
// adj^k[i][j] 表示从i到j长度为k的路径数
long long countPaths(vector<vector<int>>& adj, int start, int end, long long k) {
    int n = adj.size();
    Matrix mat(n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat.mat[i][j] = adj[i][j];
        }
    }

    Matrix result = matrixPower(mat, k);
    return result.mat[start][end];
}

// 应用4：矩阵快速幂求和
// S(n) = A + A^2 + A^3 + ... + A^n
// S(n) = A * (I + A) * (I + A^2) * (I + A^4) * ... (当n的二进制对应位为1时)
Matrix matrixPowerSum(Matrix A, long long n) {
    int size = A.n;
    Matrix result = Matrix::identity(size);
    Matrix base = A;
    Matrix power = Matrix::identity(size);

    while (n > 0) {
        if (n & 1) {
            result = result * (power + Matrix::identity(size));
        }
        power = power * (base + Matrix::identity(size));
        base = base * base;
        n >>= 1;
    }

    return result * A;
}

// Catalan数的矩阵形式
// C(n) = C(0)*C(n-1) + C(1)*C(n-2) + ... + C(n-1)*C(0)
long long catalan(int n) {
    // 使用公式: C(n) = C(2n, n) / (n+1)
    // 或者用递推关系
    if (n <= 1) return 1;

    vector<long long> c(n + 1);
    c[0] = c[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            c[i] = (c[i] + c[j] * c[i-1-j]) % MOD;
        }
    }

    return c[n];
}

// 使用示例
int main() {
    // 斐波那契数列
    cout << "Fibonacci numbers:" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << "F(" << i << ") = " << fibonacci(i) << endl;
    }

    long long n = 1000000;
    cout << "\nF(" << n << ") = " << fibonacci(n) << endl;

    // 线性递推
    // 例：a[n] = 2*a[n-1] + 3*a[n-2], a[0]=1, a[1]=2
    cout << "\nLinear recurrence:" << endl;
    vector<long long> coeffs = {2, 3};
    vector<long long> initial = {1, 2};
    LinearRecurrence lr(coeffs, initial);

    for (int i = 0; i <= 10; i++) {
        cout << "a[" << i << "] = " << lr.getNth(i) << endl;
    }

    // 矩阵乘法示例
    cout << "\nMatrix multiplication:" << endl;
    Matrix A(2, 2);
    A.mat[0][0] = 1; A.mat[0][1] = 1;
    A.mat[1][0] = 1; A.mat[1][1] = 0;

    cout << "Base matrix:" << endl;
    A.print();

    Matrix result = matrixPower(A, 5);
    cout << "\nA^5 = " << endl;
    result.print();

    return 0;
}
