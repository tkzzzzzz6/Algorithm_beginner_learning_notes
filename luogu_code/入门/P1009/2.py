n = eval(input())

def calc_factorial(n):
    s = 1
    for i in range(1,n+1):
        s *= i
    return s

s = 0
for i in range(1,n+1):
    s += calc_factorial(i)
print(s)
