from collections import defaultdict

from typing import List


class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        res = [0] * k
        m1 = defaultdict(set)
        for idx, time in logs:
            m1[idx].add(time)
        for k, v in m1.items():
            res[len(v) - 1] += 1
        return res
