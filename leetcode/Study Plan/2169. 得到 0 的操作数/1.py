# out of time 
class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        cnt = 0
        while num1 != 0 or num2 !=0:
            if num1>=num2:
                num1-=num2
                cnt+=1
            else:
                num2 -=num1
                cnt+=1
        return cnt