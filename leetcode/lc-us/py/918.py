from typing import List


class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n, res = len(nums), float('-inf')
        s = [0] * (n * 2)
        for i in range(1, n * 2):
            s[i] = s[i - 1] + nums[(i - 1) % n]
        q = [0]
        for i in range(1, n * 2):
            while q and i - q[0] > n:
                q = q[1:]
            if q:
                res = max(res, s[i] - s[q[0]])
            while q and s[q[-1]] >= s[i]:
                q = q[:-1]
            q.append(i)
        return res
