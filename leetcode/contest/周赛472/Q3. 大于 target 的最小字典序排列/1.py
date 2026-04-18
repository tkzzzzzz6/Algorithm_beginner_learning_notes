class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        from collections import Counter

        n = len(s)
        count = Counter(s)  # ͳsÿַĿôڻʱָ״̬

        def dfs(i:int, greater:bool):

            if i == n:
                return "" if greater else None

            if greater:
                result = []
                for c in sorted(count.keys()):  # ĸ˳
                    result.extend([c] * count[c])  # ַظcount[c]
                return ''.join(result)

            for c in sorted(count.keys()):
                if count[c] == 0:
                    continue

                if c < target[i]:
                    continue

                new_greater = (c > target[i])

                count[c] -= 1

                rest = dfs(i + 1, greater or new_greater)

                count[c] += 1

                if rest is not None:
                    return c + rest

            return None

        result = dfs(0, False)

        return result if result else ""
