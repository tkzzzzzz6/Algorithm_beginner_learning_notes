#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    // 1. 声明和初始化
    cout << "=== C++ HashMap (unordered_map) 基础使用 ===" << endl;

    // 方法1: 默认构造
    unordered_map<string, int> hashmap1;

    // 方法2: 初始化列表构造
    unordered_map<string, int> hashmap2 = {
        {"apple", 10},
        {"banana", 20},
        {"orange", 15}};

    // 方法3: 拷贝构造
    unordered_map<string, int> hashmap3(hashmap2);

    // 2. 插入元素
    cout << "\n--- 插入元素 ---" << endl;

    // 方法1: 使用 [] 操作符
    hashmap1["apple"] = 10;
    hashmap1["banana"] = 20;
    hashmap1["orange"] = 15;

    // 方法2: 使用 insert()
    hashmap1.insert({"grape", 25});
    hashmap1.insert(make_pair("kiwi", 30));

    // 方法3: 使用 emplace() (推荐，效率更高)
    hashmap1.emplace("mango", 18);

    // 打印所有元素
    cout << "hashmap1 内容:" << endl;
    for (const auto &pair : hashmap1)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 3. 查找元素
    cout << "\n--- 查找元素 ---" << endl;

    // 方法1: 使用 find()
    auto it = hashmap1.find("apple");
    if (it != hashmap1.end())
    {
        cout << "找到 apple: " << it->second << endl;
    }
    else
    {
        cout << "未找到 apple" << endl;
    }

    // 方法2: 使用 count()
    if (hashmap1.count("banana"))
    {
        cout << "banana 存在，值为: " << hashmap1["banana"] << endl;
    }

    // 方法3: 使用 [] 操作符（注意：如果key不存在会创建）
    cout << "orange 的值: " << hashmap1["orange"] << endl;

    // 4. 修改元素
    cout << "\n--- 修改元素 ---" << endl;
    hashmap1["apple"] = 100; // 修改apple的值
    cout << "修改后 apple 的值: " << hashmap1["apple"] << endl;

    // 5. 删除元素
    cout << "\n--- 删除元素 ---" << endl;

    // 方法1: 使用 erase(key)
    hashmap1.erase("banana");
    cout << "删除 banana 后，hashmap1 大小: " << hashmap1.size() << endl;

    // 方法2: 使用 erase(iterator)
    auto iter = hashmap1.find("orange");
    if (iter != hashmap1.end())
    {
        hashmap1.erase(iter);
        cout << "删除 orange 后，hashmap1 大小: " << hashmap1.size() << endl;
    }

    // 6. 容器信息
    cout << "\n--- 容器信息 ---" << endl;
    cout << "大小: " << hashmap1.size() << endl;
    cout << "是否为空: " << (hashmap1.empty() ? "是" : "否") << endl;
    cout << "最大容量: " << hashmap1.max_size() << endl;

    // 7. 清空容器
    hashmap1.clear();
    cout << "清空后大小: " << hashmap1.size() << endl;

    return 0;
}