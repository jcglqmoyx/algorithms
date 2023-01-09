import heapq
from heapq import heapify

from typing import List


class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        q = [-x for x in nums]
        heapify(q)
        res = 0
        while k:
            t = -heapq.heappop(q)
            res += t
            heapq.heappush(q, -((t + 2) // 3))
            k -= 1
        return res
