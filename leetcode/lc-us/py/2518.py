from typing import List


class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        if sum(nums) < k * 2:
            return 0
        mod = 10 ** 9 + 7
        tot = pow(2, len(nums), mod)
        f = [1] + [0] * (k - 1)
        for x in nums:
            for i in range(k - 1, x - 1, -1):
                f[i] = (f[i] + f[i - x]) % mod
        return ((tot - sum(f) * 2) % mod + mod) % mod
