from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        pos = {}
        for i in range(len(nums)):
            if target - nums[i] in pos:
                return [pos[target - nums[i]], i]
            pos[nums[i]] = i
        return []
