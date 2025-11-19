n = int(input())

for i in range(1,n+1):
    if i%4 == 0 or '4' in str(i):
        continue
    else:
        print(i)