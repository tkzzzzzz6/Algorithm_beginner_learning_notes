from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
    
        # 按照区间的start排序
        intervals.sort(key=lambda x: x[0])
        result = [intervals[0]]
        
        for i in range(1, len(intervals)):
            # 如果当前区间的start小于result最后一个区间的end
            # 说明当前区间和result最后一个区间重叠
            if intervals[i][0] <= result[-1][1]:
                result[-1][1] = max(intervals[i][1], result[-1][1])
            else:
                result.append(intervals[i])
        
        return result

if __name__ == '__main__':
    s = Solution()
    print(s.merge([[1,3],[2,6],[8,10],[15,18]]))