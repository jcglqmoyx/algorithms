from typing import List


class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        tot = 0
        for i, cost in enumerate(costs):
            tot += cost
            if tot > coins:
                return i
        return len(costs) if tot <= coins else 0
