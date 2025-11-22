n = int(input())
days = []
for i in range(n):
    w,d = map(int,input().split())
    days.append(w+1+(d-1)*7)

min_day = min(days)

print(min_day)
