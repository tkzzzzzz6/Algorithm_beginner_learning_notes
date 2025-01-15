#include <bits/stdc++.h> // 包含C++标准库

using namespace std;
int a[2000000], n, m; // 定义数组a和变量n,m。n是范围上限,m是输入数的个数

int main()
{
    cin >> n >> m; // 输入n和m
    for (int i = 0; i < m; i++)
        cin >> a[i]; // 循环读入m个数到数组a中
    
    sort(a, a + m); // 使用sort函数对数组a中的m个数进行升序排序
    
    for (int i = 0; i < m; i++)
        cout << a[i] << " "; // 循环输出排序后的m个数,每个数后面加空格
    return 0;
}