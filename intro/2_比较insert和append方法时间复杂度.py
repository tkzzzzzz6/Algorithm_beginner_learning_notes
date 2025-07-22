import timeit  # 导入timeit模块用于计时

# 测试在列表头部插入元素的时间复杂度
def test1():
    li = []  # 新建空列表
    for i in range(1000):
        li.insert(0, i)  # 每次都在列表头部插入元素

# 测试在列表尾部插入元素的时间复杂度
def test2():
    li = []  # 新建空列表
    for i in range(1000):
        li.append(i)  # 每次都在列表尾部插入元素

# 创建计时器，测试test1函数执行1000次所需时间
timer1 = timeit.Timer("test1()", "from __main__ import test1")
print("insert take:", timer1.timeit(1000))  # 输出insert方法的耗时

# 创建计时器，测试test2函数执行1000次所需时间
timer2 = timeit.Timer("test2()", "from __main__ import test2")
print("append take:", timer2.timeit(1000))  # 输出append方法的耗时