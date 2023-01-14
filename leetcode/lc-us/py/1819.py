from typing import List


class Solution:
    def countDifferentSubsequenceGCDs(self, nums: List[int]) -> int:
        mx = max(nums)

        def gcd(x: int, y: int) -> int:
            if x % y == 0:
                return y
            return gcd(y, x % y)

        num_set = set(nums)
        res = 0
        for i in range(1, mx + 1):
            g = -1
            for j in range(i, mx + 1, i):
                if j not in num_set:
                    continue
                if g == -1:
                    g = j
                else:
                    g = gcd(g, j)
                j += i
                if g == i:
                    res += 1
                    break
        return res
