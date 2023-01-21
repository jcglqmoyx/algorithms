from typing import List


class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        path, res = [], []

        def dfs(u: int) -> None:
            if u == len(nums):
                if len(path) >= 2:
                    res.append(path[:])
                return
            if not path or path[-1] < nums[u]:
                dfs(u + 1)

                path.append(nums[u])
                dfs(u + 1)
                path.pop()
            elif path[-1] == nums[u]:
                path.append(nums[u])
                dfs(u + 1)
                path.pop()
            else:
                dfs(u + 1)

        dfs(0)
        return res
