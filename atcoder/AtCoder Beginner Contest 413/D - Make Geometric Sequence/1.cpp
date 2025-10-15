#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

// 检查两个浮点数是否相等（考虑精度误差）
bool isEqual(double a, double b, double eps = 1e-9)
{
    return abs(a - b) < eps;
}

// 检查序列是否能重排成等比数列
bool canFormGeometricSequence(const vector<int> &A)
{
    int n = A.size();

    // 统计每个元素出现的次数
    map<int, int> count;
    for (int x : A)
    {
        count[x]++;
    }

    // 如果序列长度为1，任何序列都是等比数列
    if (n == 1)
        return true;

    // 计算所有可能的公比值
    set<double> ratios;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && A[j] != 0)
            {
                double ratio = (double)A[i] / A[j];
                ratios.insert(ratio);
            }
        }
    }

    // 对每个公比值进行验证
    for (double r : ratios)
    {
        // 尝试以每个元素作为第一个元素
        for (int first : A)
        {
            vector<int> sequence;
            sequence.push_back(first);

            // 根据公比计算后续元素
            bool valid = true;
            map<int, int> temp_count = count;
            temp_count[first]--;
            if (temp_count[first] == 0)
                temp_count.erase(first);

            for (int i = 1; i < n; i++)
            {
                double next_val = first * pow(r, i);

                // 找到最接近的整数值
                int next_int = round(next_val);

                // 检查这个整数值是否在剩余元素中
                if (temp_count.find(next_int) == temp_count.end() || temp_count[next_int] == 0)
                {
                    valid = false;
                    break;
                }

                temp_count[next_int]--;
                if (temp_count[next_int] == 0)
                    temp_count.erase(next_int);
                sequence.push_back(next_int);
            }

            if (valid)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        if (canFormGeometricSequence(A))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
