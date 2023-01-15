from typing import List


class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        res = 0
        for x in nums:
            res += x
            while x:
                res -= x % 10
                x //= 10
        return res
