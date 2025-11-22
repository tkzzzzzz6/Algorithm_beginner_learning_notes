import calendar
x,y = map(int,input().split())

day_in_month = calendar.monthrange(x,y)
print(day_in_month[1])

