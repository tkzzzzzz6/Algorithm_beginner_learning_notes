from statistics import mean
scores = [int(x) for x in input().split()]

if mean(scores) < 60:
	print("YES")
else:
	print("NO")
