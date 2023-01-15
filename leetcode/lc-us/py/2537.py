from collections import defaultdict

from typing import List


class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        res, pairs = 0, 0
        cnt = defaultdict(int)
        l, r = 0, 0
        while r < len(nums):
            pairs += cnt[nums[r]]
            cnt[nums[r]] += 1
            r += 1
            while pairs >= k:
                pairs -= cnt[nums[l]] - 1
                cnt[nums[l]] -= 1
                l += 1
            res += l
        return res
