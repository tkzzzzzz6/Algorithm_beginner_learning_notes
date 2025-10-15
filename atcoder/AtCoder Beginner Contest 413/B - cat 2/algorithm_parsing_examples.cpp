#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    cout << "=== 算法题中常见的行解析模式 ===" << endl;

    // 模式1: 读取一行包含多个整数的数据
    cout << "\n模式1: 读取一行多个整数" << endl;
    cout << "示例输入: 1 2 3 4 5" << endl;
    cout << "请输入一行整数: ";

    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nums;
    int x;
    while (ss >> x)
    {
        nums.push_back(x);
    }

    cout << "解析结果: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    // 模式2: 读取一行字符串数组
    cout << "\n模式2: 读取一行字符串数组" << endl;
    cout << "示例输入: apple banana orange" << endl;
    cout << "请输入一行字符串: ";

    string str_line;
    getline(cin, str_line);
    stringstream str_ss(str_line);
    vector<string> strings;
    string word;
    while (str_ss >> word)
    {
        strings.push_back(word);
    }

    cout << "解析结果: ";
    for (const string &s : strings)
    {
        cout << "[" << s << "] ";
    }
    cout << endl;

    // 模式3: 读取特定格式的数据
    cout << "\n模式3: 读取特定格式 (例如: N=5, M=10)" << endl;
    cout << "请输入格式: N=数字, M=数字: ";

    string format_line;
    getline(cin, format_line);

    int N = 0, M = 0;
    size_t n_pos = format_line.find("N=");
    size_t m_pos = format_line.find("M=");

    if (n_pos != string::npos)
    {
        size_t comma_pos = format_line.find(',', n_pos);
        if (comma_pos != string::npos)
        {
            N = stoi(format_line.substr(n_pos + 2, comma_pos - n_pos - 2));
        }
    }

    if (m_pos != string::npos)
    {
        M = stoi(format_line.substr(m_pos + 2));
    }

    cout << "解析结果: N=" << N << ", M=" << M << endl;

    // 模式4: 读取键值对数据
    cout << "\n模式4: 读取键值对 (例如: name=John, age=25, city=NYC)" << endl;
    cout << "请输入键值对: ";

    string kv_line;
    getline(cin, kv_line);

    map<string, string> kv_pairs;
    stringstream kv_ss(kv_line);
    string pair;

    while (getline(kv_ss, pair, ','))
    {
        size_t equal_pos = pair.find('=');
        if (equal_pos != string::npos)
        {
            string key = pair.substr(0, equal_pos);
            string value = pair.substr(equal_pos + 1);
            // 去除前后空格
            key.erase(0, key.find_first_not_of(" \t"));
            key.erase(key.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);
            kv_pairs[key] = value;
        }
    }

    cout << "解析结果:" << endl;
    for (const auto &kv : kv_pairs)
    {
        cout << "  " << kv.first << " = " << kv.second << endl;
    }

    // 模式5: 读取混合数据类型
    cout << "\n模式5: 读取混合数据类型 (例如: 字符串 数字 字符串)" << endl;
    cout << "请输入混合数据: ";

    string mixed_line;
    getline(cin, mixed_line);
    stringstream mixed_ss(mixed_line);

    string str1, str2;
    int number;

    mixed_ss >> str1 >> number >> str2;

    cout << "解析结果: 字符串1=" << str1 << ", 数字=" << number << ", 字符串2=" << str2 << endl;

    return 0;
}