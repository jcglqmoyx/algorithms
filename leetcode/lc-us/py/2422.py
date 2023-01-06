from typing import List


class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        cnt = 0
        i, j = 0, len(nums) - 1
        while i < j:
            while nums[i] < nums[j]:
                nums[i + 1] += nums[i]
                i += 1
                cnt += 1
            while nums[j] < nums[i]:
                nums[j - 1] += nums[j]
                j -= 1
                cnt += 1
            if nums[i] == nums[j]:
                i += 1
                j -= 1
            else:
                continue
        return cnt
