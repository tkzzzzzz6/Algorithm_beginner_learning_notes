class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        ans = 0
        for s in operations:
            if(s=='++X' or s == 'X++'):
                ans+=1
            else:
                ans-=1

        return ans
c