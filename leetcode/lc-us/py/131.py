from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        path, res = [], []

        def valid(i: int, j: int) -> bool:
            while i < j:
                if s[i] != s[j]:
                    return False
                i += 1
                j -= 1
            return True

        def dfs(u: int, pre: int, tot: int) -> None:
            if u == len(s):
                if tot == len(s): res.append(path[:])
                return
            dfs(u + 1, pre, tot)
            if valid(pre, u):
                path.append(s[pre: u + 1])
                dfs(u + 1, u + 1, tot + u - pre + 1)
                path.pop()

        dfs(0, 0, 0)
        return res
