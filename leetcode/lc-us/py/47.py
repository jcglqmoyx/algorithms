from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        n, res = len(nums), []
        path = [0] * n
        st = [False] * n
        nums.sort()

        def dfs(u: int) -> None:
            if u == n:
                res.append(path[:])
                return
            for i in range(n):
                if st[i] or i and nums[i - 1] == nums[i] and not st[i - 1]:
                    continue
                st[i] = True
                path[u] = nums[i]
                dfs(u + 1)
                st[i] = False

        dfs(0)
        return res
