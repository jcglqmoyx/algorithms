from typing import List


class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        n = len(parent)
        g = [[] for _ in range(n)]
        for i in range(1, n):
            g[parent[i]].append(i)

        def dfs(u: int) -> List[int]:
            a, b = 0, 0
            mx = 0
            for x in g[u]:
                t = dfs(x)
                mx = max(mx, t[1])
                if s[u] != s[x]:
                    if t[0] > b:
                        if t[0] > a:
                            b, a = a, t[0]
                        else:
                            b = t[0]
            mx = max(mx, a + b + 1)
            return [a + 1, mx]

        t = dfs(0)
        return max(t[0], t[1])
