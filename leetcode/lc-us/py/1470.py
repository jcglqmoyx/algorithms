from typing import List


class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        res = [0] * (n * 2)
        u, i, j = 0, 0, n
        while u < len(res):
            res[u] = nums[i]
            res[u + 1] = nums[j]
            u += 2
            i += 1
            j += 1
        return res
