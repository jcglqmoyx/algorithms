from collections import defaultdict

from typing import List


class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        m = defaultdict(int)
        m[0] = 1
        s = res = 0
        for num in nums:
            s = (s + num) % k
            res += m[s]
            m[s] += 1
        return res
