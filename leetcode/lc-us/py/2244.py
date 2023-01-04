from collections import Counter

from typing import List


class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        cnt = Counter(tasks)
        res = 0
        for _, freq in cnt.items():
            if freq == 1:
                return -1
            res += (freq + 2) // 3
        return res
