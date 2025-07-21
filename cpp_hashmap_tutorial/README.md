# C++ HashMap (unordered_map) 完整教程

## 📖 目录
1. [基础知识](#基础知识)
2. [基本操作](#基本操作)
3. [高级用法](#高级用法)
4. [性能优化](#性能优化)
5. [常见算法题](#常见算法题)
6. [最佳实践](#最佳实践)
7. [常见陷阱](#常见陷阱)

## 🎯 基础知识

### 什么是HashMap？
HashMap是一种基于哈希表实现的关联容器，用于存储键值对，提供快速的插入、删除和查找操作。

### C++中的实现
- `std::unordered_map` - 无序哈希映射（推荐）
- `std::map` - 基于红黑树的有序映射（不是HashMap）
- `std::unordered_multimap` - 允许重复键的无序哈希映射

### 时间复杂度
| 操作 | 平均时间复杂度 | 最坏时间复杂度 |
|------|---------------|---------------|
| 插入 | O(1) | O(n) |
| 删除 | O(1) | O(n) |
| 查找 | O(1) | O(n) |

## 🚀 基本操作

### 1. 声明和初始化
```cpp
#include <unordered_map>

// 默认构造
unordered_map<string, int> map1;

// 初始化列表
unordered_map<string, int> map2 = {
    {"apple", 10},
    {"banana", 20}
};

// 拷贝构造
unordered_map<string, int> map3(map2);
```

### 2. 插入元素
```cpp
// 方法1: [] 操作符
map1["key"] = value;

// 方法2: insert()
map1.insert({"key", value});
map1.insert(make_pair("key", value));

// 方法3: emplace() (推荐)
map1.emplace("key", value);
```

### 3. 查找元素
```cpp
// 方法1: find() (推荐)
auto it = map1.find("key");
if (it != map1.end()) {
    cout << it->second << endl;
}

// 方法2: count()
if (map1.count("key")) {
    // key 存在
}

// 方法3: at() (安全)
try {
    int value = map1.at("key");
} catch (const out_of_range& e) {
    // key 不存在
}
```

### 4. 删除元素
```cpp
// 按键删除
map1.erase("key");

// 按迭代器删除
auto it = map1.find("key");
if (it != map1.end()) {
    map1.erase(it);
}

// 清空
map1.clear();
```

### 5. 遍历
```cpp
// C++17 结构化绑定 (推荐)
for (const auto& [key, value] : map1) {
    cout << key << ": " << value << endl;
}

// 传统方式
for (const auto& pair : map1) {
    cout << pair.first << ": " << pair.second << endl;
}
```

## 🔧 高级用法

### 1. 自定义类型作为Key
```cpp
struct Person {
    string name;
    int age;
    
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

struct PersonHash {
    size_t operator()(const Person& p) const {
        return hash<string>()(p.name) ^ (hash<int>()(p.age) << 1);
    }
};

unordered_map<Person, string, PersonHash> personMap;
```

### 2. 复杂值类型
```cpp
unordered_map<string, vector<int>> studentGrades;
unordered_map<int, unordered_map<string, double>> nestedMap;
```

### 3. pair作为Key
```cpp
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

unordered_map<pair<int, int>, string, PairHash> coordinateMap;
```

## ⚡ 性能优化

### 1. 预分配空间
```cpp
unordered_map<int, string> map1;
map1.reserve(1000);  // 预分配桶数量
```

### 2. 使用emplace而不是insert
```cpp
// 更高效
map1.emplace("key", value);

// 较低效
map1.insert(make_pair("key", value));
```

### 3. 避免不必要的查找
```cpp
// 错误：两次查找
if (map1.find("key") != map1.end()) {
    cout << map1["key"] << endl;
}

// 正确：一次查找
auto it = map1.find("key");
if (it != map1.end()) {
    cout << it->second << endl;
}
```

## 🎯 常见算法题应用

### 1. 两数之和
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}
```

### 2. 字符频率统计
```cpp
unordered_map<char, int> countChars(string s) {
    unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
    }
    return count;
}
```

### 3. 前缀和问题
```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        if (prefixSum.count(sum - k)) {
            count += prefixSum[sum - k];
        }
        prefixSum[sum]++;
    }
    return count;
}
```

## 💡 最佳实践

### 1. 选择合适的查找方式
- 使用 `find()` 进行安全查找
- 使用 `at()` 进行有异常保护的访问
- 避免用 `[]` 进行查找（会意外插入）

### 2. 合理使用const
```cpp
void processMap(const unordered_map<string, int>& map) {
    // 只读操作，使用const引用
    auto it = map.find("key");
    if (it != map.end()) {
        cout << it->second << endl;
    }
}
```

### 3. 异常安全
```cpp
// 使用RAII和智能指针
unordered_map<string, unique_ptr<Object>> objectMap;
```

## ⚠️ 常见陷阱

### 1. 使用[]操作符的副作用
```cpp
unordered_map<string, int> map1;

// 错误：如果key不存在，会插入默认值
if (map1["nonexistent"] == 0) {  // 插入了 "nonexistent": 0
    // ...
}

// 正确：使用find()
if (map1.find("nonexistent") == map1.end()) {
    // key不存在
}
```

### 2. 迭代器失效
```cpp
for (auto it = map1.begin(); it != map1.end(); ++it) {
    if (condition) {
        map1.erase(it);  // 危险：迭代器失效
        // 应该使用: it = map1.erase(it);
    }
}
```

### 3. 自定义哈希函数的要求
```cpp
// 必须满足：如果 a == b，则 hash(a) == hash(b)
struct BadHash {
    size_t operator()(const Person& p) const {
        return rand();  // 错误：不确定性
    }
};
```

## 📋 性能对比

| 容器类型 | 查找时间 | 插入时间 | 内存开销 | 有序性 |
|----------|----------|----------|----------|--------|
| unordered_map | O(1)平均 | O(1)平均 | 较高 | 无序 |
| map | O(log n) | O(log n) | 较低 | 有序 |
| vector | O(n) | O(1)末尾 | 最低 | 有序 |

## 🛠️ 编译和运行

```bash
# 编译基础示例
g++ -std=c++17 basic_usage.cpp -o basic_usage
./basic_usage

# 编译高级示例
g++ -std=c++17 advanced_usage.cpp -o advanced_usage
./advanced_usage

# 编译算法示例
g++ -std=c++17 algorithm_problems.cpp -o algorithm_problems
./algorithm_problems
```

## 📚 参考资料

- [C++ Reference - unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)
- [C++ STL Documentation](https://www.cplusplus.com/reference/unordered_map/unordered_map/)
- [LeetCode HashMap Problems](https://leetcode.com/tag/hash-table/)

---

*最后更新：2024年* 