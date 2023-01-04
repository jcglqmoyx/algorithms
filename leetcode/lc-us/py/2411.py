from typing import List


class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        res = [1] * len(nums)
        for i, x in enumerate(nums):
            for j in range(i - 1, -1, -1):
                if nums[j] | x == nums[j]:
                    break
                nums[j] |= x
                res[j] = i - j + 1
        return res
