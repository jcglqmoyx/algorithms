from typing import List


class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        f = [float("-inf")] * (target + 1)
        f[0] = 0
        for c in cost:
            for x in range(c, target + 1):
                f[x] = max(f[x], f[x - c] + 1)
        if f[target] <= 0:
            return "0"
        res = ''
        j = target
        for i in range(8, -1, -1):
            while j >= cost[i] and f[j] == f[j - cost[i]] + 1:
                res += str(i + 1)
                j -= cost[i]
        return res
