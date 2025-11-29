import sys
from dataclasses import dataclass

input = lambda: sys.stdin.readline().rstrip()

@dataclass
class Interval:
    start: int
    end: int
    
    def length(self):
        return self.end - self.start + 1
    
    def intersects(self, other):
        return self.end >= other.start and self.start <= other.end
    
    def merge(self, other):
        return Interval(min(self.start, other.start), max(self.end, other.end))


def solve():
    l, m = map(int, input().split())
    
    # 读取所有区间
    intervals = []
    for _ in range(m):
        s, e = map(int, input().split())
        # s = math.ceil(s) 如果s和e是小数的话
        # e = math.floor(e)
        intervals.append(Interval(s, e))
    
    # 按起始位置排序
    intervals.sort(key=lambda x: x.start)
    
    # 合并重叠区间
    merged = [intervals[0]]
    for i in range(1, len(intervals)):
        if intervals[i].start <= merged[-1].end:
            # 有重叠，合并
            merged[-1] = merged[-1].merge(intervals[i])
        else:
            # 无重叠，添加新区间
            merged.append(intervals[i])
    
    # 计算被移除的树数
    removed = 0
    for interval in merged:
        removed += interval.length()
    
    # 剩余的树数
    tree_remain = l + 1 - removed
    print(tree_remain)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

# 采用标记数组的方法
# import sys
# input = lambda: sys.stdin.readline().rstrip()

# def solve():
#     l, m = map(int, input().split())
    
#     # 标记数组，记录每棵树是否被移除
#     removed = [False] * (l + 1)
    
#     for _ in range(m):
#         s, e = map(int, input().split())
#         for i in range(s, e + 1):
#             removed[i] = True
    
#     # 统计剩余的树
#     tree_remain = sum(1 for x in removed if not x)
#     print(tree_remain)


# if __name__ == "__main__":
#     t = 1
#     for _ in range(t):
#         solve()