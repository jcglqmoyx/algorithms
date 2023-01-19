from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        i = j = 0
        while j < n:
            nums[i] = nums[j]
            i += 1
            k = j + 1
            while k < n and nums[k] == nums[j]:
                k += 1
            j = k
        return i
