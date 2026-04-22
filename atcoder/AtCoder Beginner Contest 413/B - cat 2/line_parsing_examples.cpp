#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "=== C++ 行读取和解析示例 ===" << endl;

    // 方法1: 使用 getline() 读取整行
    cout << "\n方法1: 使用 getline() 读取整行" << endl;
    string line;
    cout << "请输入一行文本: ";
    getline(cin, line);
    cout << "读取到的行: " << line << endl;

    // 方法2: 使用 stringstream 解析空格分隔的数据
    cout << "\n方法2: 解析空格分隔的整数" << endl;
    cout << "请输入一行整数(空格分隔): ";
    string numbers_line;
    getline(cin, numbers_line);

    stringstream ss(numbers_line);
    vector<int> numbers;
    int num;
    while (ss >> num)
    {
        numbers.push_back(num);
    }

    cout << "解析出的整数: ";
    for (int n : numbers)
    {
        cout << n << " ";
    }
    cout << endl;

    // 方法3: 使用 stringstream 解析逗号分隔的数据
    cout << "\n方法3: 解析逗号分隔的字符串" << endl;
    cout << "请输入一行字符串(逗号分隔): ";
    string csv_line;
    getline(cin, csv_line);

    vector<string> csv_data;
    stringstream csv_ss(csv_line);
    string item;
    while (getline(csv_ss, item, ','))
    {
        csv_data.push_back(item);
    }

    cout << "解析出的字符串: ";
    for (const string &s : csv_data)
    {
        cout << "[" << s << "] ";
    }
    cout << endl;

    // 方法4: 手动解析特定格式
    cout << "\n方法4: 手动解析特定格式" << endl;
    cout << "请输入格式: 姓名:年龄:城市 (例如: 张三:25:北京): ";
    string format_line;
    getline(cin, format_line);

    size_t pos1 = format_line.find(':');
    size_t pos2 = format_line.find(':', pos1 + 1);

    if (pos1 != string::npos && pos2 != string::npos)
    {
        string name = format_line.substr(0, pos1);
        string age_str = format_line.substr(pos1 + 1, pos2 - pos1 - 1);
        string city = format_line.substr(pos2 + 1);

        cout << "姓名: " << name << endl;
        cout << "年龄: " << age_str << endl;
        cout << "城市: " << city << endl;
    }

    // 方法5: 使用 cin.getline() 读取固定长度
    cout << "\n方法5: 读取固定长度的行" << endl;
    char buffer[100];
    cout << "请输入一行文本(最多99字符): ";
    cin.getline(buffer, 100);
    cout << "读取到的内容: " << buffer << endl;

    return 0;
}