class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        cnt0 = [s.count('0') for s in strs]

        @cache
        def dfs(i:int,j:int,k:int)->int:
            if i < 0:
                return 0
            res = dfs(i-1,j,k)
            cnt1 = len(strs[i]) - cnt0[i]
            if j >= cnt0[i] and k >= cnt1:
                res = max(res,dfs(i-1,j-cnt0[i],k-cnt1)+1)
            return res

        return dfs(len(strs)-1,m,n)

