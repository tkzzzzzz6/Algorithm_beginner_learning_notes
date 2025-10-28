# 采用模拟的方法，
# 遍历每一个0的位置，分别尝试将其替换为1和-1
# 然后向两边扩展，直到所有非零元素都被抵消或者无法继续扩展为止。
class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        count = 0
        nonZeros = sum(1 for num in nums if num > 0)
        n = len(nums)
        for i in range(n):
            if nums[i] == 0:
                # 方向向着左
                if self.isValid(nums,nonZeros,i,-1):
                    count += 1
                # 方向向着右
                if self.isValid(nums,nonZeros,i,1):
                    count += 1
        return count

    def isValid(self, nums, nonZeros, start, direction):
        temp = nums[:] #复制数组
        curr = start
        while nonZeros > 0 and 0 <=curr < len(nums):
            if(temp[curr]>0):
                temp[curr]-=1
                direction *= -1
                if temp[curr] == 0:
                    nonZeros -= 1
            curr += direction
        return nonZeros == 0

