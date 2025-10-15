x = int(input())
a, b = 0, 0
num1, num2, num3, num4 = 0, 0, 0, 0

# 判断是否是偶数
if x % 2 == 0:
    a = 1

# 判断是否大于4且不大于12
if 4 < x <= 12:
    b = 1

# 根据条件更新num1, num2, num3, num4的值
if a == 1 and b == 1:
    num1 = 1
if a == 1 or b == 1:
    num2 = 1
if (a == 1 and b == 0) or (a == 0 and b == 1):
    num3 = 1
if a == 0 and b == 0:
    num4 = 1

# 输出结果
print(f'{num1} {num2} {num3} {num4}')