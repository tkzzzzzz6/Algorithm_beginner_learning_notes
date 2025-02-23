n,k = map(int,input().split())

a = list(map(int,input().split()))

if len(a) != n:
    print("输入的数字数量不匹配")
else:
    a[k-1] = -a[k-1]
    sum = 0
    for i in range(n):
        sum += a[i]
    print(sum)

