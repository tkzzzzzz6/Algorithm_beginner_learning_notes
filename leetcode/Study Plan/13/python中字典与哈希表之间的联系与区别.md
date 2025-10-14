
# 1.字典与哈希表之间的联系
**联系**：

1. 底层实现：Python的字典在底层是通过哈希表实现的。这意味着字典实际上就是一个哈希表的Python实现。

2. 键值对存储：两者都使用键值对的方式来存储数据。

3. 快速查找：由于使用哈希算法，两者都能够提供近乎O(1)的平均时间复杂度来进行查找、插入和删除操作。

4. 唯一键：两者都要求键是唯一的。在字典中，如果you尝试插入一个已存在的键，新值会覆盖旧值。

# 2.字典与哈希表之间的区别
**区别**：

1. 抽象层次：
   - 字典是Python中的一个高级数据结构，直接提供给程序员使用。
   - 哈希表是一个更底层的概念，是字典的实现方式。

2. 使用方式：
   - 字典有特定的Python语法，如使用花括号{}创建，使用方括号[]访问元素。
   - 哈希表是一个通用概念，不同语言可能有不同的实现方式。

3. 功能和方法：
   - Python的字典提供了许多内置方法，如keys(), values(), items()等。
   - 纯粹的哈希表通常只提供基本的增删改查操作。

4. 可见性：
   - 在Python中，你直接操作字典，而不需要关心底层的哈希表实现。
   - 哈希表的具体实现细节（如哈希函数、冲突解决策略）对Python用户是不可见的。

5. 键的类型限制：
   - Python字典的键必须是可哈希的（hashable），这包括不可变类型如字符串、数字、元组。
   - 理论上的哈希表可以使用任何可以转换为唯一整数的对象作为键。

6. 有序性：
   - 从Python 3.7开始，字典保留了插入顺序。
   - 传统的哈希表概念中并不保证有序性。

# 3.字典示例代码：

```python
# 创建一个字典
my_dict = {'apple': 1, 'banana': 2, 'cherry': 3}

# 访问元素
print(my_dict['apple'])  # 输出: 1

# 添加新元素
my_dict['date'] = 4

# 使用字典方法
print(my_dict.keys())  # 输出: dict_keys(['apple', 'banana', 'cherry', 'date'])

# 遍历字典
for key, value in my_dict.items():
    print(f"{key}: {value}")
```


# 4.简单的哈希表示例代码:

```python
class SimpleHashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(self.size)]
    
    def _hash(self, key):
        return hash(key) % self.size
    
    def insert(self, key, value):
        index = self._hash(key)
        for item in self.table[index]:
            if item[0] == key:
                item[1] = value
                return
        self.table[index].append([key, value])
    
    def get(self, key):
        index = self._hash(key)
        for item in self.table[index]:
            if item[0] == key:
                return item[1]
        raise KeyError(key)
    
    def remove(self, key):
        index = self._hash(key)
        for i, item in enumerate(self.table[index]):
            if item[0] == key:
                del self.table[index][i]
                return
        raise KeyError(key)

# 使用示例
hash_table = SimpleHashTable()
hash_table.insert("apple", 5)
hash_table.insert("banana", 7)
print(hash_table.get("apple"))  # 输出: 5
hash_table.remove("apple")
try:
    print(hash_table.get("apple"))
except KeyError:
    print("Key not found")  # 输出: Key not found

```

这个简单的哈希表实现包含了以下关键点:

1. 使用列表的列表作为底层存储结构。
2. 实现了基本的哈希函数(_hash)。
3. 提供了插入(insert)、获取(get)和删除(remove)操作。
4. 使用链地址法处理哈希冲突。

这个实现展示了哈希表的基本原理,但与Python的内置字典相比,它还缺少许多优化和功能。Python的字典使用了更复杂的冲突解决策略、动态调整大小等高级特性。

# 5.总结
## 字典与哈希表的联系:

底层实现: Python的字典在底层就是使用哈希表实现的。
时间复杂度: 两者的查找、插入和删除操作的平均时间复杂度都是O(1)。
键值对: 两者都存储键值对。

## 区别:

抽象级别: 字典是一种高级数据结构,而哈希表是一种底层实现方式。
使用方式: 字典提供了更友好的接口和更多的内置方法。
冲突处理: Python的字典内部自动处理了哈希冲突,而自定义哈希表需要手动处理。
