from collections import defaultdict

from typing import List


class Solution:
    def maxOutput(self, n: int, edges: List[List[int]], price: List[int]) -> int:
        down, up = defaultdict(int), defaultdict(int)
        parent = defaultdict(int)
        degree = defaultdict(int)
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
            degree[u] += 1
            degree[v] += 1

        def dfs1(u, p):
            parent[u] = p
            d = 0
            for v in g[u]:
                if v != p:
                    t = dfs1(v, u)
                    d = max(d, t)
            down[u] = d + price[u]
            return down[u]

        def dfs2(u, p):
            if p == -1:
                up[u] = price[u]
            else:
                t = up[p] + price[u]
                for v in g[p]:
                    if v == parent[p] or v == u:
                        continue
                    t = max(t, down[v] + price[u] + price[p])
                up[u] = t
            for v in g[u]:
                if v != p:
                    dfs2(v, u)

        dfs1(0, -1)
        dfs2(0, -1)
        res = 0
        for i in range(n):
            if degree[i] == 1:
                res = max(res, down[i] + up[i] - price[i] * 2)
        return res
