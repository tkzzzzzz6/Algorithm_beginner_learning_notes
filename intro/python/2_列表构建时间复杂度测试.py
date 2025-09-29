# codeing utf-8

from timeit import Timer

li1 = [1,2]

li2 = [3,4]

li = li1 + li2  

li = [i for i in range(10000)]

li = list(range(1000))

def test1():
    li = []
    for i in range(10000):
        li.append(i)

def test2():
    li = []
    for i in range(10000):
        li += [i]

def test3():
    li = [i for i in range(10000)]

def test4():
    li = list(range(10000))

def test5():
    li = []
    for i in range(10000):
        li.extend([i])


timer1 = Timer("test1()","from __main__ import test1") 
print("append:",timer1.timeit(1000))

timer2 = Timer("test2()","from __main__ import test2") 
print("+:",timer2.timeit(1000))

timer3 = Timer("test3()","from __main__ import test3") 
print("列表推导式:",timer3.timeit(1000))

timer4 = Timer("test4()","from __main__ import test4") 
print("构建list:",timer4.timeit(1000))

timer5 = Timer("test5","from __main__ import test5")
print("extend:",timer5.timeit(1000))