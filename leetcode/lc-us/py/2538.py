from typing import List


class Solution:
    def __init__(self):
        self.res = 0

    def maxOutput(self, n: int, edges: List[List[int]], price: List[int]) -> int:
        g = [[] for _ in range(n)]
        for e in edges:
            x, y = e
            g[x].append(y)
            g[y].append(x)

        def dfs(u: int, p: int) -> tuple[int, int]:
            s1, s2 = 0, price[u]
            for v in g[u]:
                if v != p:
                    a, b = dfs(v, u)
                    self.res = max(self.res, max(s1 + b, s2 + a))
                    s1 = max(s1, a + price[u])
                    s2 = max(s2, b + price[u])

            return s1, s2

        dfs(0, -1)
        return self.res
