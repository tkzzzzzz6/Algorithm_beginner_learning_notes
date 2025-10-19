// 引入输入输出流头文件
#include <iostream>

// 使用标准命名空间
using namespace std;

int main()
{
    // 关闭同步流,提高IO速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读入测试用例数量
    int t;
    cin >> t;
    while (t--)  // 处理每个测试用例
    {
        // 读入字符串长度n和字符串s
        int n;
        string s;
        cin >> n >> s;

        // 统计字符串中'-'和'_'的数量
        int c = 0, m = 0; // c统计'-'，m统计'_'
        for (char ch : s)
        {
            if (ch == '-')
                c++;
            else
                m++;
        }

        // 如果字符串长度小于3,或'-'数量小于2,或'_'数量小于1,输出0
        if (n < 3 || c < 2 || m < 1)
        {
            cout << "0\n";
            continue;
        }

        // 将'-'分成左右两部分
        int left = c / 2;        // 左边'-'的数量
        int right = c - left;    // 右边'-'的数量
        // 计算并输出结果: '_'的数量 * 左边'-'的数量 * 右边'-'的数量
        cout << (long long)m * left * right << '\n';
    }
    return 0;
}
