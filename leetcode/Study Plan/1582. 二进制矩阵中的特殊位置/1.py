'''
Author: tkzzzzzz6
Date: 2026-03-04 15:36:35
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-04 15:36:42
'''
class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        ans = 0
        for row in mat:
            if sum(row) != 1:
                continue
            # 找出只有一个1的行,并找出该列1对应的索引
            j = row.index(1)
            # 求j列是否也只有一个1
            if(sum(row[j] for row in mat)) == 1:
                ans += 1

        return ans
