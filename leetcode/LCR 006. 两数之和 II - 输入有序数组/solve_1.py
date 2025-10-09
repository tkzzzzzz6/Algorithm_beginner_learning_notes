# 相向双指针
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers)-1
        while True: # left < right
            sum = numbers[left] + numbers[right]
            if (sum == target):
                break
            if (sum > target):
                # 大的减小
                right -= 1
            else:
                # 小的增大
                left += 1
        return [left,right]