# e3_1逆序输出
# code1
'''
input
1
2
3
output
3
2
1
'''
a = []
while True:
    try:
        x = int(input())
        a.append(x)
    except EOFError:
        break
for i in range(len(a)-1,-1,-1):
    print(a[i])

#code2
'''
input
1 2 3
output
3 2 1
'''

a = []  # 用于存放所有读取到的整数
while True:  # 无限循环读取输入（可用 Ctrl+D/Ctrl+Z 触发 EOF 结束）
    line = input().strip()  # 读取一行并去除首尾空白字符
    if line:  # 若该行非空，则解析其中的数字
        numbers = [int(x) for x in line.split(" ")]  # 按空格分割，逐个转为 int
        a.extend(numbers)  # 将解析出的数字追加到列表 a
    # 注意：打印循环位于 while 内部，因此每次读取后都会逆序输出当前所有元素
    result =[]
    for i in range(len(a)-1, -1, -1):  # 从最后一个元素到第一个元素遍历
        result.append(str(a[i]))  # 按逆序逐个打印
    print(" ".join(result))
