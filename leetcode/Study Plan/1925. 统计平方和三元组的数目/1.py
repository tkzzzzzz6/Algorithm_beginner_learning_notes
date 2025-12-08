class Solution:
    def countTriples(self,n:int)->int:
        ans = 0
        for a in range(1,n+1):
            for b in range(1,a):
                if a*a+b*b>n*n:
                    break
                c2 = a*a+b*b
                if iSqrt(c2)**2 == c2:
                    ans+=1

        return ans*2
