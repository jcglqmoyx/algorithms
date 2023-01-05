from collections import Counter

from typing import List


class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        s, res = sum(nums[:k - 1]), 0
        cnt = Counter(nums[0:k - 1])
        for come, go in zip(nums[k - 1:], nums):
            cnt[come] += 1
            s += come
            if len(cnt) == k:
                res = max(res, s)
            s -= go
            cnt[go] -= 1
            if not cnt[go]:
                del cnt[go]
        return res
