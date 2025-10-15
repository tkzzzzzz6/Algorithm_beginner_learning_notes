week = []
max_value = 0
max_index = -1

for i in range(7):
    x,y = map(int,input().split())
    week.append(x+y)
    if x+y > max_value:
        max_value = x+y
    max_index = i

if max_value > 8:
    print(week.index(max_value)+1)
else:
    print(0)

        