from typing import List


class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        s = 1
        coins.sort()
        for x in coins:
            if s >= x:
                s += x
            else:
                break
        return s
