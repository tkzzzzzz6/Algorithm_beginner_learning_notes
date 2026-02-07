'''
Author: tkzzzzzz6
Date: 2026-02-06 22:02:11
LastEditors: tkzzzzzz6
LastEditTime: 2026-02-06 22:10:13
'''
import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Triangle:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

def get_area(T):
    # TODO: 计算三角形T的面积
    ax,ay = T.a.x,T.a.y
    bx,by = T.b.x,T.b.y
    cx,cy = T.c.x,T.c.y

    da = math.hypot(bx-ax,by-ay)
    db = math.hypot(cx-ax,cy-ay)
    dc = math.hypot(cx-bx,cy-by)

    p = (da + db + dc) / 2

    return math.sqrt(p*(p-da)*(p-db)*(p-dc))

def main():
    x, y = map(int, input().split())
    a = Point(x, y)
    
    x, y = map(int, input().split())
    b = Point(x, y)
    
    x, y = map(int, input().split())
    c = Point(x, y)
    
    T = Triangle(a, b, c)
    print("{:.2f}".format(get_area(T)))

if __name__ == "__main__":
    main()
