x,y = map(int,input().split())

work_days = 0

for day in range(y):
    current_day = (x+day-1)%7+1
    if current_day not in [6,7]:
        work_days += 1
    
print(work_days * 250)
