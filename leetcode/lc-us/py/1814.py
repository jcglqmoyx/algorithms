from collections import defaultdict

from typing import List


class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        res = 0
        cnt = defaultdict(int)
        for num in nums:
            rev = int(str(num)[::-1])
            res += cnt[num - rev]
            res %= 10 ** 9 + 7
            cnt[num - rev] += 1
        return res
