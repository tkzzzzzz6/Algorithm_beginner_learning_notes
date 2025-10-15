n = int(input())

fish_size = input().split()

for i in range(n):
    cnt = 0
    for j in range(i):
        if fish_size[j] < fish_size[i]:
            cnt += 1
    print(cnt,end=' ')

