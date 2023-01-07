from typing import List


class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        n = len(nums)
        res = n + 1
        s, i, j = 0, 0, 0
        while i < n:
            while j < n + i + 1 and s < x:
                s += nums[j % n]
                j += 1
            if s == x:
                if i == 0 or j >= n:
                    res = min(res, j - i)
                s -= nums[i]
                i += 1
            elif s > x:
                while i < n and s > x:
                    s -= nums[i]
                    i += 1
            else:
                break
        return -1 if res == n + 1 else res
