class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y
        
def cal_distance(p1,p2):
    return ((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2) ** 0.5

def cal_circumference(p1,p2,p3):
    a = cal_distance(p1,p2)
    b = cal_distance(p2,p3)
    c = cal_distance(p3,p1)
    return a + b + c

def main():
    x1,y1 = map(float,input().split())
    x2,y2 = map(float,input().split())
    x3,y3 = map(float,input().split())
    p1 = Point(x1,y1)
    p2 = Point(x2,y2)
    p3 = Point(x3,y3)
    print(f"{cal_circumference(p1,p2,p3):.2f}")

if __name__ == "__main__":
    main()
