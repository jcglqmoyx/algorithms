from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        i, n = 0, len(gas)
        while i < n:
            g, j = gas[i], i + 1
            while j < i + n + 1:
                g -= cost[(j - 1 + n) % n]
                if g >= 0:
                    if j == i + n:
                        return i
                    g += gas[j % n]
                    j += 1
                else:
                    i = j
                    break
        return -1
