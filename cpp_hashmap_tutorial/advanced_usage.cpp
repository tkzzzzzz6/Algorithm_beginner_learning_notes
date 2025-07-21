#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <functional>

using namespace std;

// 自定义结构体
struct Person
{
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}

    // 重载相等操作符
    bool operator==(const Person &other) const
    {
        return name == other.name && age == other.age;
    }
};

// 自定义哈希函数
struct PersonHash
{
    size_t operator()(const Person &p) const
    {
        return hash<string>()(p.name) ^ (hash<int>()(p.age) << 1);
    }
};

// 使用 pair 作为 key 的示例
struct PairHash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int main()
{
    cout << "=== C++ HashMap 高级用法 ===" << endl;

    // 1. 自定义类型作为 key
    cout << "\n--- 自定义类型作为 key ---" << endl;

    unordered_map<Person, string, PersonHash> personMap;

    Person p1("Alice", 25);
    Person p2("Bob", 30);

    personMap[p1] = "Engineer";
    personMap[p2] = "Designer";

    cout << p1.name << " 的职业: " << personMap[p1] << endl;
    cout << p2.name << " 的职业: " << personMap[p2] << endl;

    // 2. pair 作为 key
    cout << "\n--- pair 作为 key ---" << endl;

    unordered_map<pair<int, int>, string, PairHash> coordinateMap;

    coordinateMap[{0, 0}] = "原点";
    coordinateMap[{1, 1}] = "右上";
    coordinateMap[{-1, -1}] = "左下";

    for (const auto &item : coordinateMap)
    {
        cout << "(" << item.first.first << ", " << item.first.second
             << "): " << item.second << endl;
    }

    // 3. 复杂值类型
    cout << "\n--- 复杂值类型 ---" << endl;

    unordered_map<string, vector<int>> studentGrades;

    studentGrades["Alice"] = {95, 87, 92};
    studentGrades["Bob"] = {88, 76, 84};
    studentGrades["Charlie"] = {92, 95, 89};

    // 计算平均成绩
    for (const auto &student : studentGrades)
    {
        double average = 0;
        for (int grade : student.second)
        {
            average += grade;
        }
        average /= student.second.size();
        cout << student.first << " 的平均成绩: " << average << endl;
    }

    // 4. 实际应用：单词频率统计
    cout << "\n--- 实际应用：单词频率统计 ---" << endl;

    string text = "hello world hello cpp world programming cpp is fun";
    unordered_map<string, int> wordCount;

    // 简单的单词分割（实际应用中可能需要更复杂的处理）
    string word = "";
    for (char c : text + " ")
    {
        if (c == ' ')
        {
            if (!word.empty())
            {
                wordCount[word]++;
                word = "";
            }
        }
        else
        {
            word += c;
        }
    }

    cout << "单词频率统计:" << endl;
    for (const auto &item : wordCount)
    {
        cout << item.first << ": " << item.second << endl;
    }

    // 5. 实际应用：两数之和问题
    cout << "\n--- 实际应用：两数之和问题 ---" << endl;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    unordered_map<int, int> numMap;

    cout << "数组: [";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i < nums.size() - 1)
            cout << ", ";
    }
    cout << "], 目标值: " << target << endl;

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end())
        {
            cout << "找到解: 索引 " << numMap[complement]
                 << " 和 " << i << " (值: " << complement
                 << " + " << nums[i] << " = " << target << ")" << endl;
            break;
        }
        numMap[nums[i]] = i;
    }

    // 6. 性能相关操作
    cout << "\n--- 性能相关操作 ---" << endl;

    unordered_map<int, string> perfMap;

    // 预分配空间（提高性能）
    perfMap.reserve(1000);

    // 批量插入
    for (int i = 0; i < 100; i++)
    {
        perfMap.emplace(i, "value" + to_string(i));
    }

    cout << "容器信息:" << endl;
    cout << "大小: " << perfMap.size() << endl;
    cout << "桶数量: " << perfMap.bucket_count() << endl;
    cout << "负载因子: " << perfMap.load_factor() << endl;
    cout << "最大负载因子: " << perfMap.max_load_factor() << endl;

    // 7. 安全查找（避免意外插入）
    cout << "\n--- 安全查找 ---" << endl;

    unordered_map<string, int> safeMap = {
        {"apple", 10},
        {"banana", 20}};

    // 错误方式：使用 [] 会意外插入
    // cout << safeMap["grape"] << endl;  // 这会插入 grape: 0

    // 正确方式：使用 at() 或 find()
    try
    {
        cout << "apple 的值: " << safeMap.at("apple") << endl;
        cout << "grape 的值: " << safeMap.at("grape") << endl; // 抛出异常
    }
    catch (const out_of_range &e)
    {
        cout << "grape 不存在: " << e.what() << endl;
    }

    // 使用 find() 的安全方式
    auto it = safeMap.find("grape");
    if (it != safeMap.end())
    {
        cout << "grape 的值: " << it->second << endl;
    }
    else
    {
        cout << "grape 不存在" << endl;
    }

    // 8. 遍历方式对比
    cout << "\n--- 遍历方式对比 ---" << endl;

    unordered_map<string, int> iterMap = {
        {"one", 1}, {"two", 2}, {"three", 3}};

    // 方式1: 基于范围的for循环（推荐）
    cout << "方式1 - 基于范围的for循环:" << endl;
    for (const auto &[key, value] : iterMap)
    { // C++17结构化绑定
        cout << key << ": " << value << endl;
    }

    // 方式2: 传统迭代器
    cout << "方式2 - 传统迭代器:" << endl;
    for (auto it = iterMap.begin(); it != iterMap.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }

    // 方式3: 只遍历键或值
    cout << "只遍历键:" << endl;
    for (const auto &item : iterMap)
    {
        cout << item.first << " ";
    }
    cout << endl;

    return 0;
}