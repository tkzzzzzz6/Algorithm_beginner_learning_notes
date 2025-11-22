n,a,b = map(int,input().split())
cnt = 0
for i in range(n):
    if i - a == b:
        if i - a >= 0:
            print(i,end=" ")
            cnt += 1
    if a - i == b and i-a != 0:
        if a - i >= 0:
            print(i,end=" ")
            cnt += 1

if cnt == 0:
    print("No solution")

