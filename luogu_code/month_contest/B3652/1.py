n = int(input())


a = list(map(int,input().split()))
    
max_value = max(a)
min_value = min(a)

print(*[max_value - x for x in a])
print(*[x - min_value for x in a])
