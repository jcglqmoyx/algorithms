from collections import defaultdict

from typing import List


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        res = i = j = 0
        cnt = defaultdict(int)
        while j < len(fruits):
            cnt[fruits[j]] += 1
            while len(cnt) > 2:
                cnt[fruits[i]] -= 1
                if cnt[fruits[i]] == 0:
                    del cnt[fruits[i]]
                i += 1
            res = max(res, j - i + 1)
            j += 1
        return res
