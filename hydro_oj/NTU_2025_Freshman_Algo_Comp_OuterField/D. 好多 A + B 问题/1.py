n = int(input())

# method 1
while n>0:
    a,b = [int(x) for x in input().split()]
    ans = a+b
    print(ans)
    n -= 1

# method 2
while n>0:
    a,b = map(int,input().split())
    ans = a+b
    print(ans)
    n-=1