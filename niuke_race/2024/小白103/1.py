# from collections import Counter

# t = int(input())
# a = []
# b = []
# for i in range(t):
#     n = int(input().strip())  
#     for j in range(n):
#         a = Counter(list(map(int,input().split())))
#         cnt = 0
#         for item,count in a.items():
#             if count == 1 or count == 2:continue
#             else:
#                 zhouchang = item * count
#                 b.append(zhouchang)
#                 cnt += 1
#         if cnt == 0:
#             print("no")
#         else:
#             print("yes")
#             print(max(b))
#         b.clear()
        

from collections import Counter

def find_min_polygon(sticks):
    count = Counter(sticks)
    min_perimeter = float('inf')
    found = False

    for length, num in count.items():
        for sides in range(3, num + 1):  # 从3边开始尝试，直到当前长度木棍的数量
            if num >= sides:
                perimeter = sides * length
                if perimeter < min_perimeter:
                    min_perimeter = perimeter
                    found = True

    if found:
        return f"yes\n{min_perimeter}"
    else:
        return "no"

t = int(input())
for _ in range(t):
    n = int(input())
    sticks = list(map(int, input().split()))
    print(find_min_polygon(sticks))
